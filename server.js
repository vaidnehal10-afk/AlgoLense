const express = require("express");
const cors = require("cors");
const { execFile } = require("child_process");
const path = require("path");

const app = express();
app.use(cors());
app.use(express.json());

// Path to compiled C program
const exePath = path.join(__dirname, "AlgoLense.exe");

// API route to run the C program
app.post("/run", (req, res) => {
    const input = req.body.input || "";

    const process = execFile(exePath, [], (error, stdout, stderr) => {
        if (error) {
            res.json({ output: "ERROR: " + error.message });
            return;
        }
        res.json({ output: stdout });
    });

    process.stdin.write(input);
    process.stdin.end();
});

// Start the server
const PORT = 5000;
app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
});
