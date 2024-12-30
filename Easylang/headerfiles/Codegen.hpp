#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include "AST.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include <map>
#include <memory>
#include <string>

//===----------------------------------------------------------------------===//
// Code Generation
//===----------------------------------------------------------------------===//

extern std::unique_ptr<llvm::LLVMContext> TheContext;
extern std::unique_ptr<llvm::Module> TheModule;
extern std::unique_ptr<llvm::IRBuilder<>> Builder;
extern std::map<std::string, llvm::Value*> NamedValues;

// Function to log errors and return nullptr for LLVM Values
llvm::Value* LogErrorV(const char* Str);

#endif // CODEGEN_HPP
