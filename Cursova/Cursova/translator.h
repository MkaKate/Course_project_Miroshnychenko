#pragma once

#define MAX_TOKENS 1000
#define MAX_IDENTIFIER 10

// �������������, ��� ����� �� ������ ���� ������
enum TypeOfTokens
{
    Mainprogram,
    StartProgram,
    Variable,
    Type,
    EndProgram,
    Input,
    Output,

    If,
    Then,
    Else,

    Goto,
    Label,

    For,
    To,
    DownTo,
    Do,

    While,
    Exit,
    Continue,
    End,

    Repeat,
    Until,

    Identifier,
    Number,
    Assign,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Equality,
    NotEquality,
    Greate,
    Less,
    Not,
    And,
    Or,
    LBraket,
    RBraket,
    Semicolon,
    Colon,
    Comma,
    Minus,
    Unknown
};

// ��������� ��� ��������� ���������� ��� �������
struct Token
{
    char name[16];      // ��'� �������
    int value;          // �������� ������� (��� ����� ��������)
    int line;           // ����� �����
    TypeOfTokens type;  // ��� �������
};

// ��������� ��� ��������� ���������� ��� �������������
struct Id
{
    char name[16];
};

// �������������, ��� ����� ����� ���������� ����������
enum States
{
    Start,      // ������� �������� ������� �������    
    Finish,     // ����� �������� ������� �������
    Letter,     // ����������� ��� (������ ����� � ��������������)
    Digit,      // ����������� �����
    Separators, // ��������� ������, ������� ��������� � �������� �� ����� �����
    Another,    // ����������� ����� �������
    EndOfFile,  // ����� �����
    SComment,   // ������� ���������
    Comment     // ��������� ���������
};


// �������������, ��� ����� �� ������ ����� ������������ ������������� ������
enum TypeOfNodes
{
    program_node,
    var_node,
    input_node,
    output_node,

    if_node,
    then_node,

    goto_node,
    label_node,

    for_to_node,
    for_downto_node,

    while_node,
    exit_while_node,
    continue_while_node,

    repeat_until_node,

    id_node,
    num_node,
    assign_node,
    add_node,
    sub_node,
    mul_node,
    div_node,
    mod_node,
    or_node,
    and_node,
    not_node,
    cmp_node,
    minus_node,
    statement_node,
    compount_node
};

// ���������, ��� ����� ����� ������������ ������������� ������ (AST)
struct ASTNode
{
    TypeOfNodes nodetype;    // ��� �����
    char name[16];           // ��'� �����
    struct ASTNode* left;    // ˳��� �������
    struct ASTNode* right;   // ������ �������
};

// ������� ������ ������� � �������� ����� F � ������ �� � ������� ������ TokenTable
// ��������� ������� - ������� ������
unsigned int GetTokens(FILE* F, Token TokenTable[], FILE* errFile);

// ������� ����� ������� ������ �� �����
void PrintTokens(Token TokenTable[], unsigned int TokensNum);

// ������� ����� ������� ������ � ����
void PrintTokensToFile(char* FileName, Token TokenTable[], unsigned int TokensNum);

// ������������ ����� ������� ������������ ������
// ����� ��� - ��������� ������� ������ TokenTable
void Parser(FILE* errFile);

// ������� ������������� ������ � ��������� ������������ ������������� ������
ASTNode* ParserAST();

// ������� �������� ������
void destroyTree(ASTNode* root);

// ������� ��� ����� AST � ������ ������ �� �����
void PrintAST(ASTNode* node, int level);

// ������� ��� ����� AST � ������ ������ � ����
void PrintASTToFile(ASTNode* node, int level, FILE* outFile);

// ���������� ������� ��� ��������� ���� � AST
void generateCodefromAST(ASTNode* node, FILE* output);

// ������� ��� ��������� ����
void generateCCode(FILE* outFile);

void compile_to_exe(const char* source_file, const char* output_file);

