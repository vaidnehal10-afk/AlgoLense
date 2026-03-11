const express = require("express");
const cors = require("cors");
const { execFile } = require("child_process");
const path = require("path");

const app = express();
app.use(cors());
app.use(express.json());

// Serve frontend
app.use(express.static(path.join(__dirname, "frontend")));

// API route to run the C program
app.post("/run", (req, res) => {
    const input = req.body.input || "";

    execFile("gcc", ["main.c", "-o", "program"], (compileErr) => {
        if (compileErr) {
            res.json({ output: "Compilation Error: " + compileErr.message });
            return;
        }

        const runProcess = execFile("./program", [], (error, stdout) => {
            if (error) {
                res.json({ output: "Runtime Error: " + error.message });
                return;
            }
            res.json({ output: stdout });
        });

        runProcess.stdin.write(input);
        runProcess.stdin.end();
    });
});

const PORT = process.env.PORT || 5000;

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
