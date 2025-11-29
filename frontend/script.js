/* ==========================================================
   PART 1 — PROBLEM METADATA
   ========================================================== */


const problems = [
    { id: 1, name: "GCD & LCM", desc: "Find GCD and LCM.", variations: [
        { key: "1_1", label: "Euclid Iterative" },
        { key: "1_2", label: "Euclid Recursive" },
        { key: "1_3", label: "Binary GCD (Stein)" }
    ]},

    { id: 2, name: "Prime Check", desc: "Check if a number is prime.", variations: [
        { key: "2_1", label: "Classic sqrt" },
        { key: "2_2", label: "6k ± 1 Optimization" }
    ]},

    { id: 3, name: "Factorial", desc: "Compute factorial.", variations: [
        { key: "3_1", label: "Iterative" },
        { key: "3_2", label: "Recursive" },
        { key: "3_3", label: "Big Integer Array" }
    ]},

    { id: 4, name: "Sum of Digits", desc: "Sum of digits of a number.", variations: [
        { key: "4_1", label: "Iterative Sum" },
        { key: "4_2", label: "Recursive Sum" }
    ]},

    { id: 5, name: "Armstrong Number", desc: "Check if number is Armstrong.", variations: [
        { key: "5_1", label: "3-digit Check" },
        { key: "5_2", label: "n-digit Check" }
    ]},

    { id: 6, name: "Anagram Check", desc: "Check whether two strings are anagrams.", variations: [
        { key: "6_1", label: "Frequency Array" },
        { key: "6_2", label: "Sorting Method" }
    ]},

    { id: 7, name: "First Non-Repeating Character", desc: "Find the first unique character.", variations: [
        { key: "7_1", label: "Frequency Method" },
        { key: "7_2", label: "Index-Map Method" }
    ]},

    { id: 8, name: "Remove Duplicates from Array", desc: "Remove repeated elements.", variations: [
        { key: "8_1", label: "O(n^2) Preserve Order" },
        { key: "8_2", label: "Sorting + Unique" }
    ]},

    { id: 9, name: "Second Largest", desc: "Find second largest element.", variations: [
        { key: "9_1", label: "Single Pass" },
        { key: "9_2", label: "Sorting Based" }
    ]},

    { id: 10, name: "Pairs with Given Sum", desc: "Find all sum pairs.", variations: [
        { key: "10_1", label: "Brute Force" },
        { key: "10_2", label: "Two Pointer" }
    ]},

    { id: 11, name: "Balanced Parentheses", desc: "Check balanced expression.", variations: [
        { key: "11_1", label: "Only ()" },
        { key: "11_2", label: "(),{},[]" }
    ]},

    { id: 12, name: "Reverse Linked List", desc: "Reverse a linked list.", variations: [
        { key: "12_1", label: "Iterative Reverse" },
        { key: "12_2", label: "Recursive Reverse" }
    ]},

    { id: 13, name: "Middle of Linked List", desc: "Find middle element.", variations: [
        { key: "13_1", label: "Slow-Fast Pointer" },
        { key: "13_2", label: "Count Method" }
    ]},

    { id: 14, name: "Merge Two Sorted Lists", desc: "Merge sorted lists.", variations: [
        { key: "14_1", label: "Linked List Merge" },
        { key: "14_2", label: "Array Merge" }
    ]},

    { id: 15, name: "Queue using Two Stacks", desc: "Queue implementation.", variations: [
        { key: "15_1", label: "Menu Driven Queue" },
        { key: "15_2", label: "Operation Sequence" }
    ]},

    { id: 16, name: "Kruskal Algorithm (MST)", desc: "Find MST using Kruskal.", variations: [
        { key: "16_1", label: "Sorting + Union-Find" },
        { key: "16_2", label: "Min-Heap + Union-Find" }
    ]},

    { id: 17, name: "Store Weighted Graph", desc: "Store adjacency list.", variations: [
        { key: "17_1", label: "Basic Adjacency List" },
        { key: "17_2", label: "Tail Pointer List" }
    ]},

    { id: 18, name: "BST Leaf Count", desc: "Count leaves in BST.", variations: [
        { key: "18_1", label: "Recursive Insert + Count" },
        { key: "18_2", label: "Iterative Insert + Count" }
    ]},

    { id: 19, name: "Binary Tree Traversals", desc: "Traverse binary tree.", variations: [
        { key: "19_1", label: "Inorder Recursive" },
        { key: "19_2", label: "Inorder Iterative" },
        { key: "19_3", label: "Preorder Recursive" }
    ]},

    { id: 20, name: "Detect Cycle in Graph", desc: "Detect cycle in graph.", variations: [
        { key: "20_1", label: "DFS Based" },
        { key: "20_2", label: "Union-Find Based" }
    ]}
];

/* ==========================================================
   PART 2 — variationCode (A to F)
   ========================================================== */

const variationCode = {

"1_1": `void findGcdLcm_A1() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    int n1 = a, n2 = b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    long long lcm = (long long)n1 * n2 / gcd;
    printf("GCD = %d, LCM = %lld", gcd, lcm);
}`,

"1_2": `int gcd_recursive(int a, int b){
    return (b==0)?a:gcd_recursive(b,a%b);
}
void findGcdLcm_A2(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    int g=gcd_recursive(a,b);
    long long lcm=(long long)a*b/g;
    printf("GCD = %d, LCM = %lld",g,lcm);
}`,

"1_3": `int binary_gcd(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    int shift=0;
    while(((a|b)&1)==0){a>>=1;b>>=1;shift++;}
    while((a&1)==0) a>>=1;
    do{
        while((b&1)==0) b>>=1;
        if(a>b){int t=b;b=a;a=t;}
        b-=a;
    }while(b);
    return a<<shift;
}
void findGcdLcm_A3(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    int g=binary_gcd(a,b);
    long long lcm=(long long)a*b/g;
    printf("GCD = %d, LCM = %lld",g,lcm);
}`,

"2_1": `void checkPrime_A1(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    if(n<=1){printf("Not Prime");return;}
    for(int i=2;i*i<=n;i++){
        if(n%i==0){printf("Not Prime");return;}
    }
    printf("Prime");
}`,

"2_2": `void checkPrime_A2(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    if(n<=1){printf("Not Prime");return;}
    if(n%2==0||n%3==0){printf("Not Prime");return;}
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0){
            printf("Not Prime");
            return;
        }
    }
    printf("Prime");
}`,
"3_1": `void findFactorial_A1(){
    int n;printf("Enter number: ");
    scanf("%d",&n);
    long long f=1;
    for(int i=2;i<=n;i++) f*=i;
    printf("Factorial = %lld",f);
}`,

"3_2": `long long fact_rec(int n){
    return (n<=1)?1:n*fact_rec(n-1);
}
void findFactorial_A2(){
    int n;printf("Enter number: ");
    scanf("%d",&n);
    printf("Factorial = %lld",fact_rec(n));
}`,

"3_3": `void findFactorial_A3(){
    int n;printf("Enter number: ");
    scanf("%d",&n);
    int a[2000],s=1;a[0]=1;
    for(int x=2;x<=n;x++){
        int carry=0;
        for(int i=0;i<s;i++){
            int p=a[i]*x+carry;
            a[i]=p%10;carry=p/10;
        }
        while(carry){a[s++]=carry%10;carry/=10;}
    }
    printf("Factorial = ");
    for(int i=s-1;i>=0;i--) printf("%d",a[i]);
}`,
"4_1": `void sumOfDigits_A1(){
    long long n;
    printf("Enter a number: ");
    scanf("%lld",&n);
    if(n<0) n=-n;
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    printf("Sum of digits = %d",sum);
}`,

"4_2": `int sum_digits_rec(long long n){
    if(n==0) return 0;
    return (int)(n%10)+sum_digits_rec(n/10);
}
void sumOfDigits_A2(){
    long long n;
    printf("Enter a number: ");
    scanf("%lld",&n);
    if(n<0) n=-n;
    printf("Sum of digits = %d",sum_digits_rec(n));
}`,
"5_1": `void checkArmstrong_A1(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int temp=n,sum=0;
    while(temp!=0){
        int d=temp%10;
        sum+=d*d*d;
        temp/=10;
    }
    if(sum==n) printf("Armstrong Number");
    else printf("Not Armstrong");
}`,

"5_2": `int int_pow(int b,int e){
    int r=1;
    while(e--) r*=b;
    return r;
}
void checkArmstrong_A2(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int temp=n,digits=0;
    while(temp!=0){
        digits++;
        temp/=10;
    }
    temp=n;
    int sum=0;
    while(temp!=0){
        int d=temp%10;
        sum+=int_pow(d,digits);
        temp/=10;
    }
    if(sum==n) printf("Armstrong Number");
    else printf("Not Armstrong");
}`,
"6_1": `void checkAnagram_A1(){
    char s1[256],s2[256];
    printf("Enter first string: ");
    scanf("%255s",s1);
    printf("Enter second string: ");
    scanf("%255s",s2);
    if(strlen(s1)!=strlen(s2)){
        printf("Not Anagram");
        return;
    }
    int freq[256]={0};
    for(int i=0;s1[i];i++){
        unsigned char a=(unsigned char)s1[i];
        unsigned char b=(unsigned char)s2[i];
        freq[a]++;
        freq[b]--;
    }
    for(int i=0;i<256;i++){
        if(freq[i]!=0){
            printf("Not Anagram");
            return;
        }
    }
    printf("Anagram Strings");
}`,

"6_2": `int cmp_char(const void *a,const void *b){
    return (*(const char*)a-*(const char*)b);
}
void checkAnagram_A2(){
    char s1[256],s2[256];
    printf("Enter first string: ");
    scanf("%255s",s1);
    printf("Enter second string: ");
    scanf("%255s",s2);
    int n1=strlen(s1),n2=strlen(s2);
    if(n1!=n2){
        printf("Not Anagram");
        return;
    }
    qsort(s1,n1,sizeof(char),cmp_char);
    qsort(s2,n2,sizeof(char),cmp_char);
    if(strcmp(s1,s2)==0) printf("Anagram Strings");
    else printf("Not Anagram");
}`,
"7_1": `void firstNonRepeat_A1(){
    char s[300];printf("Enter string: ");
    scanf("%s",s);
    int f[256]={0};
    for(int i=0;s[i];i++)f[(unsigned)s[i]]++;
    for(int i=0;s[i];i++)
        if(f[(unsigned)s[i]]==1){
            printf("First non-repeating = %c",s[i]);return;
        }
    printf("No unique character");
}`,

"7_2": `void firstNonRepeat_A2(){
    char s[300];printf("Enter string: ");
    scanf("%s",s);
    int idx[256];for(int i=0;i<256;i++)idx[i]=-1;
    for(int i=0;s[i];i++){
        unsigned c=s[i];
        if(idx[c]==-1)idx[c]=i;
        else idx[c]=-2;
    }
    int best=999999;
    for(int i=0;i<256;i++)if(idx[i]>=0&&idx[i]<best)best=idx[i];
    if(best==999999)printf("No unique character");
    else printf("First non-repeating = %c",s[best]);
}`,
"8_1": `void removeDup_A1(){
    int n;printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("After removing duplicates: ");
    for(int i=0;i<n;i++){
        int ok=1;
        for(int j=0;j<i;j++)if(a[i]==a[j])ok=0;
        if(ok)printf("%d ",a[i]);
    }
    free(a);
}`,

"8_2": `int cmp_intA(const void*A,const void*B){
    return *(int*)A-*(int*)B;
}
void removeDup_A2(){
    int n;printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,4,cmp_intA);
    printf("After removing duplicates: %d ",a[0]);
    for(int i=1;i<n;i++)if(a[i]!=a[i-1])printf("%d ",a[i]);
    free(a);
}`,
"9_1": `void secondLargest_A1(){
    int n;printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    long long f=-1e18,s=f;
    for(int i=0;i<n;i++){
        if(a[i]>f){s=f;f=a[i];}
        else if(a[i]>s&&a[i]!=f)s=a[i];
    }
    if(s==-1e18)printf("No 2nd largest");
    else printf("Second Largest = %lld",s);
    free(a);
}`,

"9_2": `int cmp_intB(const void*A,const void*B){
    return *(int*)A-*(int*)B;
}
void secondLargest_A2(){
    int n;printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,4,cmp_intB);
    int i=n-1, mx=a[i];
    while(i>=0&&a[i]==mx)i--;
    if(i<0)printf("No 2nd largest");
    else printf("Second Largest = %d",a[i]);
    free(a);
}`,
"9_1": `void secondLargest_A1(){
    int n;printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    long long f=-1e18,s=f;
    for(int i=0;i<n;i++){
        if(a[i]>f){s=f;f=a[i];}
        else if(a[i]>s&&a[i]!=f)s=a[i];
    }
    if(s==-1e18)printf("No 2nd largest");
    else printf("Second Largest = %lld",s);
    free(a);
}`,

"9_2": `int cmp_intB(const void*A,const void*B){
    return *(int*)A-*(int*)B;
}
void secondLargest_A2(){
    int n;printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    qsort(a,n,4,cmp_intB);
    int i=n-1, mx=a[i];
    while(i>=0&&a[i]==mx)i--;
    if(i<0)printf("No 2nd largest");
    else printf("Second Largest = %d",a[i]);
    free(a);
}`,
"10_1": `void pairsSum_A1(){
    int n,t;
    printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter target sum: ");
    scanf("%d",&t);
    printf("Pairs: \\n");
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]+a[j]==t)
                printf("(%d,%d)\\n",a[i],a[j]);
    free(a);
}`,

"10_2": `int cmp_intC(const void*A,const void*B){
    return *(int*)A-*(int*)B;
}
void pairsSum_A2(){
    int n,t;
    printf("Enter size: ");
    scanf("%d",&n);
    int*a=malloc(n*sizeof(int));
    printf("Enter elements: ");
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter target sum: ");
    scanf("%d",&t);
    qsort(a,n,4,cmp_intC);
    int i=0,j=n-1;
    printf("Pairs: \\n");
    while(i<j){
        int s=a[i]+a[j];
        if(s==t){
            printf("(%d,%d)\\n",a[i],a[j]);
            i++;j--;
        } else if(s<t)i++;
        else j--;
    }
    free(a);
}`,
"11_1": `void balanced_A1(){
    char s[300];printf("Expression: ");
    scanf("%s",s);
    char st[300];int top=-1;
    for(int i=0;s[i];i++){
        if(s[i]=='(')st[++top]='(';
        else if(s[i]==')'){
            if(top==-1){printf("Not Balanced");return;}
            top--;
        }
    }
    printf(top==-1?"Balanced":"Not Balanced");
}`,

"11_2": `void balanced_A2(){
    char s[300];printf("Expression: ");
    scanf(" %299[^\n]",s);
    char st[300];int top=-1;
    for(int i=0;s[i];i++){
        char c=s[i];
        if(c=='('||c=='{'||c=='[')st[++top]=c;
        else if(c==')'||c=='}'||c==']'){
            if(top==-1){printf("Not Balanced");return;}
            char t=st[top--];
            if((c==')'&&t!='(')||(c=='}'&&t!='{')||(c==']'&&t!='[')){
                printf("Not Balanced");return;
            }
        }
    }
    printf(top==-1?"Balanced":"Not Balanced");
}`,
"12_1": `struct Node{int data;struct Node*next;};
void reverseLL_A1(){
    int n;printf("Enter number of nodes: ");
    scanf("%d",&n);
    struct Node*head=NULL;
    for(int i=0;i<n;i++){
        int v;printf("Enter value: ");
        scanf("%d",&v);
        struct Node*t=malloc(sizeof(struct Node));
        t->data=v;t->next=head;
        head=t;
    }
    struct Node*prev=NULL,*curr=head,*nx=NULL;
    while(curr){
        nx=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nx;
    }
    printf("Reversed: ");
    while(prev){
        printf("%d ",prev->data);
        struct Node*t=prev;
        prev=prev->next;
        free(t);
    }
}`,

"12_2": `struct Node{int data;struct Node*next;};
struct Node*insertTail(struct Node*h,int v){
    struct Node*t=malloc(sizeof(struct Node));
    t->data=v;t->next=NULL;
    if(!h)return t;
    struct Node*p=h;while(p->next)p=p->next;
    p->next=t;return h;
}
struct Node*revRec(struct Node*h){
    if(!h||!h->next)return h;
    struct Node*r=revRec(h->next);
    h->next->next=h;h->next=NULL;
    return r;
}
void reverseLL_A2(){
    int n;printf("Enter number of nodes: ");
    scanf("%d",&n);
    struct Node*head=NULL;
    for(int i=0;i<n;i++){
        int v;printf("Enter value: ");
        scanf("%d",&v);
        head=insertTail(head,v);
    }
    head=revRec(head);
    printf("Reversed: ");
    while(head){
        printf("%d ",head->data);
        struct Node*t=head;head=head->next;free(t);
    }
}`,
"13_1": `struct Node{int data; struct Node*next;};

void middleNode_A1(){
    int n,val;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct Node*head=NULL;
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        struct Node*t=malloc(sizeof(*t));
        t->data=val;
        t->next=head;
        head=t;
    }

    if(!head){ printf("List empty"); return; }

    struct Node*slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    printf("Middle node = %d", slow->data);

    while(head){
        struct Node*x=head;
        head=head->next;
        free(x);
    }
}`,
"13_2": `struct Node{int data; struct Node*next;};

void middleNode_A2(){
    int n,val;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    struct Node *head=NULL,*tail=NULL;
    for(int i=0;i<n;i++){
        printf("Enter value: ");
        scanf("%d",&val);
        struct Node*nn=malloc(sizeof(*nn));
        nn->data=val;
        nn->next=NULL;

        if(!head) head=tail=nn;
        else { tail->next=nn; tail=nn; }
    }

    int cnt=0;
    struct Node*t=head;
    while(t){ cnt++; t=t->next; }

    if(cnt==0){ printf("List empty"); return; }

    int mid = cnt/2;
    t=head;
    for(int i=0;i<mid;i++) t=t->next;

    printf("Middle node = %d", t->data);

    while(head){
        struct Node*x=head;
        head=head->next;
        free(x);
    }
}`,
"14_1": `struct Node{int data; struct Node*next;};

struct Node* insert_head(int n){
    struct Node*head=NULL;
    for(int i=0;i<n;i++){
        struct Node*nn=malloc(sizeof(*nn));
        printf("Enter value: ");
        scanf("%d",&nn->data);
        nn->next=head;
        head=nn;
    }
    return head;
}

void mergeSortedLists_A1(){
    int n1,n2;
    printf("Enter number of nodes in List1: ");
    scanf("%d",&n1);
    struct Node*head1=insert_head(n1);

    printf("Enter number of nodes in List2: ");
    scanf("%d",&n2);
    struct Node*head2=insert_head(n2);

    struct Node dummy, *tail=&dummy;
    dummy.next=NULL;

    while(head1 && head2){
        if(head1->data < head2->data){
            tail->next=head1;
            head1=head1->next;
        }
        else{
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }

    tail->next = head1 ? head1 : head2;

    printf("Merged list: ");
    struct Node*t=dummy.next;
    while(t){
        printf("%d ", t->data);
        struct Node*x=t;
        t=t->next;
        free(x);
    }
}`,
"14_2": `void mergeSortedLists_A2(){
    int n1,n2;
    printf("Enter number of nodes in List1: ");
    scanf("%d",&n1);
    int *a1 = (n1>0 ? malloc(n1*sizeof(int)) : NULL);
    for(int i=0;i<n1;i++){
        printf("Enter value: ");
        scanf("%d",&a1[i]);
    }

    printf("Enter number of nodes in List2: ");
    scanf("%d",&n2);
    int *a2 = (n2>0 ? malloc(n2*sizeof(int)) : NULL);
    for(int i=0;i<n2;i++){
        printf("Enter value: ");
        scanf("%d",&a2[i]);
    }

    int i=0,j=0;
    printf("Merged list: ");
    while(i<n1 && j<n2){
        if(a1[i] <= a2[j]) printf("%d ", a1[i++]);
        else printf("%d ", a2[j++]);
    }
    while(i<n1) printf("%d ", a1[i++]);
    while(j<n2) printf("%d ", a2[j++]);

    free(a1);
    free(a2);
}`,
"15_1": `#define QSIZE 500
int q1[QSIZE],q2[QSIZE],t1=-1,t2=-1;

void push1(int x){ if(t1+1<QSIZE) q1[++t1]=x; }
void push2(int x){ if(t2+1<QSIZE) q2[++t2]=x; }
int pop1(){ return (t1==-1?-1:q1[t1--]); }
int pop2(){ return (t2==-1?-1:q2[t2--]); }

void queueUsingStacks_A1(){
    int ch,x;
    t1=t2=-1;

    while(1){
        printf("1.Enqueue\\n2.Dequeue\\n3.Display\\n0.Exit\\nEnter choice: ");
        scanf("%d",&ch);
        if(ch==0) break;

        if(ch==1){
            printf("Enter value: ");
            scanf("%d",&x);
            push1(x);
        }
        else if(ch==2){
            if(t2==-1)
                while(t1!=-1) push2(pop1());

            if(t2==-1) printf("Queue empty\\n");
            else printf("Dequeued: %d\\n", pop2());
        }
        else if(ch==3){
            printf("Queue: ");
            for(int i=t2;i>=0;i--) printf("%d ",q2[i]);
            for(int i=0;i<=t1;i++) printf("%d ",q1[i]);
            printf("\\n");
        }
        else printf("Invalid choice\\n");
    }
}`,
"15_2": `#define QSIZE 500
int s1[QSIZE],s2[QSIZE],t1=-1,t2=-1;

void enqueueX(int x){ if(t1+1<QSIZE) s1[++t1]=x; }
int dequeueX(){
    if(t2==-1) while(t1!=-1) s2[++t2]=s1[t1--];
    if(t2==-1) return -1;
    return s2[t2--];
}

void queueUsingStacks_A2(){
    int ops;
    printf("Enter number of operations: ");
    scanf("%d",&ops);

    t1=t2=-1;

    for(int i=0;i<ops;i++){
        int op;
        printf("Op (1=enq 2=deq 3=disp): ");
        scanf("%d",&op);

        if(op==1){
            int v;
            printf("Enter value: ");
            scanf("%d",&v);
            enqueueX(v);
        }
        else if(op==2){
            int v=dequeueX();
            if(v==-1) printf("Queue empty\\n");
            else printf("Dequeued: %d\\n",v);
        }
        else if(op==3){
            printf("Queue: ");
            for(int j=t2;j>=0;j--) printf("%d ",s2[j]);
            for(int j=0;j<=t1;j++) printf("%d ",s1[j]);
            printf("\\n");
        }
        else printf("Invalid\\n");
    }
}`,

"16_1": `typedef struct {
    int u,v,w;
} Edge;

typedef struct {
    int *parent,*rank,n;
} DSU;

DSU* dsu_create(int n){
    DSU*d=malloc(sizeof(*d));
    d->parent=malloc((n+1)*sizeof(int));
    d->rank=malloc((n+1)*sizeof(int));
    d->n=n;
    for(int i=0;i<=n;i++){ d->parent[i]=i; d->rank[i]=0; }
    return d;
}

int dsu_find(DSU*d,int x){
    if(d->parent[x]!=x) d->parent[x]=dsu_find(d,d->parent[x]);
    return d->parent[x];
}

void dsu_union(DSU*d,int x,int y){
    int rx=dsu_find(d,x), ry=dsu_find(d,y);
    if(rx==ry) return;
    if(d->rank[rx]<d->rank[ry]) d->parent[rx]=ry;
    else if(d->rank[ry]<d->rank[rx]) d->parent[ry]=rx;
    else{ d->parent[ry]=rx; d->rank[rx]++; }
}

int cmpEdge(const void*a,const void*b){
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

void kruskal_qsort_A1(){
    int n,m;
    printf("Enter vertices & edges: ");
    scanf("%d %d",&n,&m);

    Edge*e=malloc(m*sizeof(Edge));
    printf("Enter u v w:\\n");
    for(int i=0;i<m;i++) scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);

    qsort(e,m,sizeof(Edge),cmpEdge);

    DSU*d=dsu_create(n);
    int cnt=0;
    long long total=0;

    printf("MST edges:\\n");
    for(int i=0;i<m && cnt<n-1;i++){
        int u=e[i].u, v=e[i].v;
        if(dsu_find(d,u)!=dsu_find(d,v)){
            dsu_union(d,u,v);
            printf("(%d,%d) weight=%d\\n",u,v,e[i].w);
            total+=e[i].w;
            cnt++;
        }
    }

    if(cnt!=n-1) printf("MST not possible");
    else printf("Total weight = %lld",total);

    free(e);
    free(d->parent); free(d->rank); free(d);
}`,
"16_2": `typedef struct{int u,v,w;} Edge;
typedef struct{Edge*data; int size,cap;} MinHeap;

MinHeap*heap_create(int c){
    MinHeap*h=malloc(sizeof(*h));
    h->data=malloc((c+1)*sizeof(Edge));
    h->size=0; h->cap=c;
    return h;
}

void swapE(Edge*a,Edge*b){Edge t=*a; *a=*b; *b=t;}

void heap_push(MinHeap*h,Edge e){
    if(h->size+1>h->cap){
        h->cap=h->cap*2+1;
        h->data=realloc(h->data,(h->cap+1)*sizeof(Edge));
    }
    int i=++h->size;
    h->data[i]=e;
    while(i>1 && h->data[i].w < h->data[i/2].w){
        swapE(&h->data[i],&h->data[i/2]);
        i/=2;
    }
}

Edge heap_pop(MinHeap*h){
    Edge r=h->data[1];
    h->data[1]=h->data[h->size--];
    int i=1;
    while(1){
        int l=2*i,r2=2*i+1,s=i;
        if(l<=h->size && h->data[l].w<h->data[s].w) s=l;
        if(r2<=h->size && h->data[r2].w<h->data[s].w) s=r2;
        if(s==i) break;
        swapE(&h->data[i],&h->data[s]);
        i=s;
    }
    return r;
}

typedef struct{int *p,*r;} DSU2;

DSU2*dsu2_create(int n){
    DSU2*d=malloc(sizeof(*d));
    d->p=malloc((n+1)*sizeof(int));
    d->r=malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++){d->p[i]=i; d->r[i]=0;}
    return d;
}

int find2(DSU2*d,int x){
    if(d->p[x]!=x) d->p[x]=find2(d,d->p[x]);
    return d->p[x];
}

void union2(DSU2*d,int x,int y){
    x=find2(d,x); y=find2(d,y);
    if(x==y) return;
    if(d->r[x]<d->r[y]) d->p[x]=y;
    else if(d->r[y]<d->r[x]) d->p[y]=x;
    else{ d->p[y]=x; d->r[x]++; }
}

void kruskal_heap_A2(){
    int n,m;
    printf("Enter vertices & edges: ");
    scanf("%d %d",&n,&m);

    MinHeap*h=heap_create(m);
    printf("Enter u v w:\\n");
    for(int i=0;i<m;i++){ Edge e; scanf("%d%d%d",&e.u,&e.v,&e.w); heap_push(h,e); }

    DSU2*d=dsu2_create(n);
    int cnt=0; long long total=0;

    printf("MST edges:\\n");
    while(h->size && cnt<n-1){
        Edge e=heap_pop(h);
        if(find2(d,e.u)!=find2(d,e.v)){
            union2(d,e.u,e.v);
            printf("(%d,%d) weight=%d\\n",e.u,e.v,e.w);
            total+=e.w; cnt++;
        }
    }

    if(cnt!=n-1) printf("MST not possible");
    else printf("Total weight = %lld",total);
}`,
"17_1": `typedef struct AdjNode{
    int v,w;
    struct AdjNode*next;
}AdjNode;

void add_edge_basic(AdjNode**adj,int u,int v,int w){
    AdjNode*nn=malloc(sizeof(*nn));
    nn->v=v; nn->w=w; nn->next=adj[u];
    adj[u]=nn;
}

void storeGraph_A1(){
    int n,m;
    printf("Enter vertices & edges: ");
    scanf("%d %d",&n,&m);

    AdjNode**adj=calloc(n+1,sizeof(AdjNode*));

    printf("Enter u v w:\\n");
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge_basic(adj,u,v,w);
    }

    printf("Adjacency list:\\n");
    for(int i=1;i<=n;i++){
        printf("%d: ",i);
        for(AdjNode*p=adj[i]; p; p=p->next)
            printf("(%d,%d) ",p->v,p->w);
        printf("\\n");
    }
}`,
"17_2": `typedef struct AdjNode{
    int v,w;
    struct AdjNode*next;
}AdjNode;

typedef struct{
    AdjNode *head,*tail;
}AdjList;

void add_edge_tail(AdjList*L,int u,int v,int w){
    AdjNode*nn=malloc(sizeof(*nn));
    nn->v=v; nn->w=w; nn->next=NULL;
    if(!L[u].head) L[u].head=L[u].tail=nn;
    else{ L[u].tail->next=nn; L[u].tail=nn; }
}

void storeGraph_A2(){
    int n,m;
    printf("Enter vertices & edges: ");
    scanf("%d%d",&n,&m);

    AdjList*L=malloc((n+1)*sizeof(AdjList));
    for(int i=0;i<=n;i++){ L[i].head=L[i].tail=NULL; }

    printf("Enter u v w:\\n");
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add_edge_tail(L,u,v,w);
    }

    printf("Adjacency list:\\n");
    for(int i=1;i<=n;i++){
        printf("%d: ",i);
        for(AdjNode*p=L[i].head;p;p=p->next)
            printf("(%d,%d) ",p->v,p->w);
        printf("\\n");
    }
}`,
"18_1": `typedef struct BST{
    int val;
    struct BST *l,*r;
}BST;

BST* insertR(BST*root,int x){
    if(!root){
        BST*n=malloc(sizeof(*n));
        n->val=x; n->l=n->r=NULL;
        return n;
    }
    if(x<root->val) root->l=insertR(root->l,x);
    else root->r=insertR(root->r,x);
    return root;
}

int countLeavesR(BST*root){
    if(!root) return 0;
    if(!root->l && !root->r) return 1;
    return countLeavesR(root->l)+countLeavesR(root->r);
}

void bst_leaves_A1(){
    int n,v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    BST*root=NULL;
    printf("Enter values:\\n");
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        root=insertR(root,v);
    }

    printf("Leaf nodes = %d", countLeavesR(root));
}`,
"18_2": `typedef struct BST{
    int val;
    struct BST *l,*r;
}BST;

BST* insertIter(BST*root,int x){
    BST*n=malloc(sizeof(*n));
    n->val=x; n->l=n->r=NULL;

    if(!root) return n;

    BST*cur=root,*par=NULL;
    while(cur){
        par=cur;
        if(x<cur->val) cur=cur->l;
        else cur=cur->r;
    }
    if(x<par->val) par->l=n;
    else par->r=n;

    return root;
}

int countLeavesIter(BST*root){
    if(!root) return 0;
    BST*stk[500]; int top=-1,count=0;
    stk[++top]=root;

    while(top!=-1){
        BST*n=stk[top--];
        if(!n->l && !n->r) count++;
        if(n->r) stk[++top]=n->r;
        if(n->l) stk[++top]=n->l;
    }
    return count;
}

void bst_leaves_A2(){
    int n,v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);

    BST*root=NULL;
    printf("Enter values:\\n");
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        root=insertIter(root,v);
    }

    printf("Leaf nodes = %d", countLeavesIter(root));
}`,
"19_1": `typedef struct Node{
    int d;
    struct Node*l,*r;
}Node;

Node* build(){
    int x;
    printf("Enter node (-1 for NULL): ");
    scanf("%d",&x);
    if(x==-1) return NULL;

    Node*n=malloc(sizeof(*n));
    n->d=x;

    printf("Left of %d:\\n",x);
    n->l=build();

    printf("Right of %d:\\n",x);
    n->r=build();

    return n;
}

void inorder(Node*r){
    if(!r) return;
    inorder(r->l);
    printf("%d ",r->d);
    inorder(r->r);
}

void inorder_A1(){
    Node*root=build();
    printf("Inorder: ");
    inorder(root);
}`,
"19_2": `typedef struct Node{
    int d;
    struct Node*l,*r;
}Node;

Node* build2();

void inorderIter(Node*root){
    Node*stk[500]; int top=-1;
    Node*cur=root;

    while(cur||top!=-1){
        while(cur){
            stk[++top]=cur;
            cur=cur->l;
        }
        cur=stk[top--];
        printf("%d ",cur->d);
        cur=cur->r;
    }
}

void inorder_A2(){
    Node*root=build();
    printf("Inorder: ");
    inorderIter(root);
}`,
"19_3": `typedef struct Node{
    int d;
    struct Node*l,*r;
}Node;

Node* build3();

void preorder(Node*r){
    if(!r) return;
    printf("%d ",r->d);
    preorder(r->l);
    preorder(r->r);
}

void preorder_A3(){
    Node*root=build();
    printf("Preorder: ");
    preorder(root);
}`,
"20_1": `int dfs(int u,int **g,int *vis,int *rec,int V){
    vis[u]=1; rec[u]=1;

    for(int v=0;v<V;v++){
        if(g[u][v]){
            if(!vis[v] && dfs(v,g,vis,rec,V)) return 1;
            else if(rec[v]) return 1;
        }
    }
    rec[u]=0;
    return 0;
}

void detectCycleDFS_A1(){
    int V,E;
    printf("Enter vertices & edges: ");
    scanf("%d %d",&V,&E);

    int**g=malloc(V*sizeof(int*));
    for(int i=0;i<V;i++){ g[i]=calloc(V,sizeof(int)); }

    printf("Enter edges u v:\\n");
    for(int i=0;i<E;i++){
        int u,v; scanf("%d %d",&u,&v);
        g[u][v]=1;
    }

    int vis[V],rec[V];
    for(int i=0;i<V;i++) vis[i]=rec[i]=0;

    for(int i=0;i<V;i++){
        if(!vis[i] && dfs(i,g,vis,rec,V)){
            printf("Graph contains a cycle");
            return;
        }
    }
    printf("Graph does NOT contain a cycle");
}`,
"20_2": `int findUF(int p[],int x){
    if(p[x]==-1) return x;
    return p[x]=findUF(p,p[x]);
}

int unionUF(int p[],int x,int y){
    int px=findUF(p,x), py=findUF(p,y);
    if(px==py) return 0;
    p[px]=py;
    return 1;
}

void detectCycleUF_A2(){
    int V,E;
    printf("Enter vertices & edges: ");
    scanf("%d %d",&V,&E);

    int (*edge)[2]=malloc(E*sizeof *edge);

    printf("Enter edges u v:\\n");
    for(int i=0;i<E;i++) scanf("%d%d",&edge[i][0],&edge[i][1]);

    int p[V];
    for(int i=0;i<V;i++) p[i]=-1;

    for(int i=0;i<E;i++){
        if(!unionUF(p, edge[i][0], edge[i][1])){
            printf("Graph contains a cycle");
            return;
        }
    }

    printf("Graph does NOT contain a cycle");
}`,

};
/* ==========================================================
   PART 3 — MAIN UI HANDLERS
   ========================================================== */

let currentProblem = null;
let currentVariation = null;

// Render problems list
window.addEventListener("DOMContentLoaded", () => {
    const list = document.getElementById("problemList");
    problems.forEach(p => {
        const li = document.createElement("li");
        li.textContent = `${p.id}. ${p.name}`;
        li.onclick = () => selectProblem(p);
        list.appendChild(li);
    });
});

// Select problem
function selectProblem(p) {
    currentProblem = p;
    currentVariation = null;

    document.getElementById("welcomeBox").classList.add("hidden");
    document.getElementById("problemBox").classList.remove("hidden");

    document.getElementById("problemTitle").textContent = p.name;
    document.getElementById("problemDesc").textContent = p.desc;

    document.getElementById("variationSection").classList.add("hidden");
    document.getElementById("codeSection").classList.add("hidden");
}

// Show variations
function openVariations() {
    const vs = document.getElementById("variationSection");
    const list = document.getElementById("variationList");
    list.innerHTML = "";

    vs.classList.remove("hidden");
    currentProblem.variations.forEach(v => {
        const btn = document.createElement("button");
        btn.className = "variation-btn";
        btn.textContent = v.label;
        btn.onclick = () => selectVariation(v, btn);
        list.appendChild(btn);
    });
}

// Select variation → show code
function selectVariation(v, btn) {
    currentVariation = v;

    document.querySelectorAll(".variation-btn")
        .forEach(b => b.classList.remove("active"));
    btn.classList.add("active");

    const codeSec = document.getElementById("codeSection");
    codeSec.classList.remove("hidden");

    document.getElementById("variationTitle").textContent = v.label;

    const code = variationCode[v.key] || "Code not available.";
    document.getElementById("codeBox").textContent = code;
}

/* ==========================================================
   PART 4 — FLOWCHART MODAL
   ========================================================== */

   /* ==========================================================
   PART 6 — FLOWCHART & COMPLEXITY DATA (FULL — ALL 20)
   ========================================================== */
/* ==========================================================
   FLOWCHART DATA (converted from flowchart.c)
   ========================================================== */

const flowcharts = {
    1: [
        "Start",
        "Input two integers a, b",
        "Store originals n1=a, n2=b",
        "While b != 0:",
        "  temp = b",
        "  b = a % b",
        "  a = temp",
        "End while",
        "GCD = a",
        "LCM = (n1 * n2) / GCD (handle zero/negative)",
        "Print GCD, LCM",
        "End"
    ],

    2: [
        "Start",
        "Input n",
        "If n <= 1: Not Prime",
        "Else if n <= 3: Prime",
        "Else if n divisible by 2 or 3: Not Prime",
        "Else:",
        "  Check divisibility by i = 5, 11, 17, ... (6k±1) up to sqrt(n)",
        "If any divisor found: Not Prime; otherwise Prime",
        "End"
    ],

    3: [
        "Start",
        "Input n",
        "If n < 0 → factorial not defined",
        "Else:",
        "  fact = 1",
        "  For i = 2 to n: fact *= i",
        "  Print fact",
        "Also recursive and big-integer versions follow similar structure",
        "End"
    ],

    4: [
        "Start",
        "Input integer n",
        "sum = 0; n = |n|",
        "While n > 0:",
        "  digit = n % 10",
        "  sum += digit",
        "  n /= 10",
        "Print sum",
        "End"
    ],

    5: [
        "Start",
        "Input n",
        "Copy temp = n, sum = 0",
        "Count digits d in n",
        "While temp != 0:",
        "  digit = temp % 10",
        "  sum += digit^d",
        "  temp /= 10",
        "If sum == n → Armstrong; else Not Armstrong",
        "End"
    ],

    6: [
        "Start",
        "Input strings s1, s2",
        "If lengths differ → Not Anagram",
        "Else:",
        "  Either:",
        "   (a) Count frequency of chars in s1, subtract for s2; all zeros → Anagram",
        "  Or:",
        "   (b) Sort s1, sort s2; if equal → Anagram",
        "End"
    ],

    7: [
        "Start",
        "Input string s",
        "freq[256] = 0",
        "For each character c in s: freq[c]++",
        "For each character c in s from left to right:",
        "  If freq[c] == 1 → print c and stop",
        "If no such char → print 'No non-repeating character'",
        "End"
    ],

    8: [
        "Start",
        "Input array arr of size n",
        "For i from 0 to n-1:",
        "  Check if arr[i] appeared before index i",
        "  If not → print arr[i]",
        "Alternatively: sort arr and skip equal neighbors",
        "End"
    ],

    9: [
        "Start",
        "Input array arr of size n",
        "Initialize first = -∞, second = -∞",
        "For each arr[i]:",
        "  Update first and second appropriately",
        "If second unchanged → no second largest exists",
        "Else print second",
        "End"
    ],

    10: [
        "Start",
        "Input array arr of size n, and target sum",
        "Brute-force: nested loops (i, j>i), check arr[i]+arr[j]==target",
        "Optimized: sort arr, use two-pointer i=0, j=n-1",
        "Print all matching pairs",
        "End"
    ],

    11: [
        "Start",
        "Input expression exp",
        "Initialize empty stack",
        "For each character c in exp:",
        "  If c is opening bracket → push",
        "  If c is closing bracket:",
        "     If stack empty or types don't match → Not Balanced",
        "After processing:",
        "  If stack empty → Balanced; else Not Balanced",
        "End"
    ],

    12: [
        "Start",
        "Build linked list from input",
        "Set prev = NULL, curr = head",
        "While curr != NULL:",
        "  next = curr->next",
        "  curr->next = prev",
        "  prev = curr",
        "  curr = next",
        "head = prev",
        "Print reversed list",
        "End"
    ],

    13: [
        "Start",
        "Build linked list",
        "Set slow = head, fast = head",
        "While fast != NULL and fast->next != NULL:",
        "  slow = slow->next",
        "  fast = fast->next->next",
        "Print slow->data as middle",
        "End"
    ],

    14: [
        "Start",
        "Input two sorted lists L1, L2",
        "Use dummy node and tail pointer",
        "While L1 and L2 not NULL:",
        "  Attach smaller node to tail; move corresponding list forward",
        "Attach any remaining nodes",
        "Print merged list",
        "End"
    ],

    15: [
        "Start",
        "Initialize two stacks S1, S2",
        "Enqueue(x): push x onto S1",
        "Dequeue(): if S2 empty, move all from S1 to S2; pop from S2",
        "Display: show elements from S2 then S1",
        "End"
    ],

    16: [
        "Start",
        "Input n (vertices), m (edges)",
        "Store all edges (u, v, w)",
        "Sort edges or push into Min-Heap by weight",
        "Initialize DSU for n vertices",
        "For each edge in increasing weight:",
        "  If endpoints in different sets → union them & add edge to MST",
        "Stop when MST has n-1 edges or edges exhausted",
        "If not n-1 edges → MST not possible",
        "End"
    ],

    17: [
        "Start",
        "Input n (vertices), m (edges)",
        "Create adjacency list",
        "For each of m edges:",
        "  Input u, v, w",
        "  Allocate node and attach to list of u (and v if undirected)",
        "Print adjacency list",
        "Free nodes",
        "End"
    ],

    18: [
        "Start",
        "Input number of nodes",
        "Insert each value into BST",
        "To count leaves recursively:",
        "  If node is NULL → 0",
        "  If node has no children → 1",
        "  Else → leftLeaves + rightLeaves",
        "Print number of leaves",
        "End"
    ],

    19: [
        "Start",
        "Build binary tree from preorder, -1 means NULL",
        "Inorder (recursive): left, root, right",
        "Inorder (iterative): use stack",
        "Preorder (recursive): root, left, right",
        "End"
    ],

    20: [
        "Start",
        "Directed graph (DFS):",
        "  Maintain visited[] & recStack[]",
        "  DFS: if neighbor in recStack → cycle",
        "Undirected graph (Union-Find):",
        "  parent[] = -1",
        "  For each edge (u,v):",
        "    If find(u)==find(v) → cycle",
        "    Else union(u,v)",
        "End"
    ]
};



/* ==========================================================
   TIME & SPACE COMPLEXITY DATA (FULL — ALL 20)
   ========================================================== */

/* ==========================================================
   COMPLEXITY DATA (converted from your C code)
   ========================================================== */

const complexityData = {
    1:  "GCD & LCM: Time O(log min(a,b)), Space O(1)",
    2:  "Prime: Time O(sqrt(n)), Space O(1)",
    3:  "Factorial: Time O(n), Big-int extra digit ops; Space O(1)/O(n)",
    4:  "Sum of Digits: Time O(d), Space O(1) / O(d)",
    5:  "Armstrong: Time O(d), Space O(1)",
    6:  "Anagram: Time O(n) / O(n log n), Space O(1)/O(n)",
    7:  "First Non-Repeating Char: Time O(n), Space O(1)",
    8:  "Remove Duplicates: Time O(n²) / O(n log n), Space O(1)/O(n)",
    9:  "Second Largest: Time O(n) / O(n log n), Space O(1)",
    10: "Pairs with Sum: Time O(n²) / O(n log n), Space O(1)",
    11: "Balanced Parentheses: Time O(n), Space O(n)",
    12: "Reverse Linked List: Time O(n), Space O(1)/O(n)",
    13: "Middle Node: Time O(n), Space O(1)",
    14: "Merge Sorted Lists: Time O(n+m), Space O(1)",
    15: "Queue using Two Stacks: Amortized O(1), Space O(n)",
    16: "Kruskal: Time O(E log E), Space O(V+E)",
    17: "Store Weighted Graph: Build O(V+E), Space O(V+E)",
    18: "BST Leaf Count: Time O(n), Space O(h)/O(n)",
    19: "Traversals: Time O(n), Space O(h)/O(n)",
    20: "Cycle Detection: DFS O(V+E), UF O(E α(V)), Space O(V+E)"
};



/* ==========================================================
   UPDATED FLOWCHART + COMPLEXITY FUNCTIONS
   ========================================================== */
function showFlowchart() {
    if (!currentProblem) return alert("Select a problem first.");

    const modal = document.getElementById("flowchartModal");
    modal.classList.remove("hidden");

    const lines = flowcharts[currentProblem.id] || ["Flowchart not available."];
    document.getElementById("flowchartContent").textContent = lines.join("\n");
}


function closeFlowchartModal() {
    document.getElementById("flowchartModal").classList.add("hidden");
}

function showComplexity() {
    if (!currentProblem) return alert("Select a problem first.");

    const modal = document.getElementById("complexityModal");
    modal.classList.remove("hidden");

    const text = complexityData[currentProblem.id] || "Complexity not available.";
    document.getElementById("complexityContent").textContent = text;
}


function closeComplexityModal() {
    document.getElementById("complexityModal").classList.add("hidden");
}


