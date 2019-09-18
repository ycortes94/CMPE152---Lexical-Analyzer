#include "scanner.hpp"

using std::cout;
using std::vector;

bool isID(const std::string &str){
  if(std::isdigit(str[0]))
    return false;
  int counter = 0;
  if(str[0] == '_')
    counter++;

  for(;counter < str.size(); counter++)
    if(!(isalnum(str[counter])))
      return false;
  return true;
}

bool isComment(const std::string &str){
  return str == "/*" || str == "//";
}

bool isDigit(const std::string &str){
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool isString(const std::string &str){
  return str[0] == '"' && str[str.size()-1] == '"';
}

bool isBool(const std::string &str){
  return str == "true" || str == "false";
}

bool isNUM(const std::string &str){
  return isDigit(str) || isString(str) || isBool(str);
}

bool isKeyword(const std::string &str){
  const vector<std::string> keywords{"int", "float", "bool"};
  for(const auto& keyword : keywords)
    if (keyword == str)
      return true;
  return false;
}

bool isFor(const std::string &str){
  const vector<std::string> statements{"for"};
  for(const auto& statement : statements)
    if (statement == str)
      return true;
  return false;
}

bool isWhile(const std::string &str){
  const vector<std::string> whl{"while"};
  for(const auto& wh : whl)
    if (wh == str)
      return true;
  return false;
}

bool isOperator(const std::string &str){
  const vector<std::string> math{">", "<=", ">=", "*", "+", "-", "/", "-=", "*=", "+=", "/=", "++", "--", "=="};
  for(const auto& op : math)
    if (op == str)
      return true;
  return false;
}

bool isEqual(const std::string &str){
  const vector<std::string> Equal{"="};
  for(const auto& Eq : Equal)
    if (Eq == str)
      return true;
  return false;
}

bool isLeftBracket(const std::string &str){
	  const vector<std::string> LeftBracket{"{"};
	  for(const auto& Lb : LeftBracket)
	    if (Lb == str)
	      return true;
	  return false;
	}

bool isRightBracket(const std::string &str){
	  const vector<std::string> RightBracket{"}"};
	  for(const auto& Rb : RightBracket)
	    if (Rb == str)
	      return true;
	  return false;
	}

bool isLeftPar(const std::string &str){
	  const vector<std::string> LeftPar{"("};
	  for(const auto& Lp : LeftPar)
	    if (Lp == str)
	      return true;
	  return false;
	}

bool isRightPar(const std::string &str){
	  const vector<std::string> RightPar{")"};
	  for(const auto& Rp : RightPar)
	    if (Rp == str)
	      return true;
	  return false;
	}

bool isLessThan(const std::string &str){
  const vector<std::string> LessThan{"<"};
  for(const auto& op : LessThan)
    if (op == str)
      return true;
  return false;
}


bool isComma(const std::string &str){
  const vector<std::string> comma{","};
  for(const auto& cma : comma)
    if (cma == str)
      return true;
  return false;
}

bool isSemicolon(const std::string &str){
  const vector<std::string> semicolon{";"};
  for(const auto& sc : semicolon)
    if (sc == str)
      return true;
  return false;
}

bool isNotLegal(const std::string &str){
  return str == " " || str == "\n";
}

void printRoleOfToken(const std::string& token){
  if(isOperator(token))
    cout << "operator " << token << "\n";
  else if(isSemicolon(token))
    cout << "; " << token << "\n";
  else if(isKeyword(token))
    cout << "BASE_TYPE " << token << "\n";
  else if(isFor(token))
    cout << "FOR " << token << "\n";
  else if(isNUM(token))
    cout << "NUM " << token << "\n";
  else if(isID(token))
    cout << "ID " << token << "\n";
  else if(isEqual(token))
    cout << "= " << token << "\n";
  else if(isLeftBracket(token))
    cout << "{ " << token << "\n";
  else if(isRightBracket(token))
    cout << "} " << token << "\n";
  else if(isRightPar(token))
    cout << ") " << token << "\n";
  else if(isLeftPar(token))
    cout << "( " << token << "\n";
  else if(isLessThan(token))
    cout << "< " << token << "\n";
  else if(isComma(token))
    cout << ", " << token << "\n";
  else if(isWhile(token))
    cout << "WHILE " << token << "\n";
  else if(isComment(token))
    cout << "comment " << token << "\n";
  else
    throw std::runtime_error(token);
}

void lexicalAnalyze(const std::string &nameOfFile){
  char ch;
  std::string buffer;
  std::fstream file(nameOfFile, std::fstream::in);

  if (!file.is_open()){
    cout << "error while opening the file\n";
    exit(0);
  }

  bool miltiCm = false, singleCm = false;
  while (file >> std::noskipws >> ch){
    if(singleCm || miltiCm){
      if(singleCm && ch == '\n')
        singleCm = false;

      if(miltiCm && ch == '*'){
        file >> ch;
        if(ch == EOF)
          break;

        if(ch == '/')
          miltiCm = false;
      }
      continue;
    }

    if(ch == '/'){
      std::string comm(1, ch);
      file >> ch;
      if(ch == EOF){
        printRoleOfToken(comm);
        break;
      }

      if(ch == '*'){
        miltiCm = true;
        comm += ch;
      }
      else if(ch == '/'){
        singleCm = true;
        comm += ch;
      }
      if(miltiCm || singleCm){
        printRoleOfToken(comm);
        continue;
      }
    }

    if(isNotLegal(std::string(1, ch))){
      if(!buffer.empty())
      {
        printRoleOfToken(buffer);
        buffer = "";
      }
      continue;
    }

    if(isOperator(std::string(1, ch)))
    {
      if(!buffer.empty() && !isOperator(buffer))
      {
        printRoleOfToken(buffer);
        buffer = "";
      }
    }

    if(isSemicolon(std::string(1, ch)))
    {
      if(!buffer.empty())
      {
        printRoleOfToken(buffer);
        buffer = "";
      }
      if(isSemicolon(std::string(1, ch)))
      {
        printRoleOfToken(std::string(1, ch));
        continue;
      }
    }
    buffer += ch;
  }
  file.close();
}
