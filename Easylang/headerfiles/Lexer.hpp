#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>

// Token definitions
enum Token {
    tok_eof = -1,
    tok_def = -2,
    tok_extern = -3,
    tok_identifier = -4,
    tok_number = -5
};

// Extern variables used by the lexer
extern std::string IdentifierStr; // Filled in if tok_identifier
extern double NumVal;             // Filled in if tok_number

// Lexer function to get the next token
int gettok();

#endif // LEXER_HPP
