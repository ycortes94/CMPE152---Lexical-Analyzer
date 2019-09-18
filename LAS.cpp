#include "LAS.hpp"

using std::cout;
using std::vector;

bool isID(const std::string &str){
  if(std::isdigit(str[0])){
    return false;
  }
  int counter = 0;
  if(str[0] == '_'){
    counter++;
  }

  for(;counter<str.size();counter++)
    if(!(isalnum(str[counter])))
      return false;
  return true;
}
//===========================================================================
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

bool isBasetype(const std::string &str){
  const vector<std::string> Basetypes{"int", "float", "bool"};
  for(const auto& Basetype : Basetypes)
    if (Basetype == str)
      return true;
  return false;
}

bool isComment(const std::string &str){
  return str == "/*" || str == "//";
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
  const vector<std::string> math{"<=", ">=","-=", "*=", "+=", "/=", "++", "--"};
  for(const auto& op : math)
    if (op == str)
      return true;
  return false;
}

bool isGreaterThan(const std::string &str){
  const vector<std::string> great{">"};
  for(const auto& gt : great)
    if (gt == str)
      return true;
  return false;
}

bool isPlus(const std::string &str){
  const vector<std::string> Plus{"+"};
  for(const auto& pl : Plus)
    if (pl == str)
      return true;
  return false;
}

bool isMult(const std::string &str){
  const vector<std::string> Multiply{"*"};
  for(const auto& mt : Multiply)
    if (mt == str)
      return true;
  return false;
}

bool isMinus(const std::string &str){
  const vector<std::string> Minus{"-"};
  for(const auto& min : Minus)
    if (min == str)
      return true;
  return false;
}

bool isDivision(const std::string &str){
  const vector<std::string> Division{"/"};
  for(const auto& div : Division)
    if (div == str)
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

bool isEqualEqual(const std::string &str){
  const vector<std::string> EqualE{"=="};
  for(const auto& Eqe : EqualE)
    if (Eqe == str)
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
//===========================================================================
void printToken(const std::string& token){
  if(isOperator(token))
    cout << "operator " << token << "\n";
  else if(isSemicolon(token))
    cout << "; " << token << "\n";
  else if(isBasetype(token))
    cout << "BASE_TYPE " << token << "\n";
  else if(isFor(token))
    cout << "FOR " << token << "\n";
  else if(isNUM(token))
    cout << "NUM " << token << "\n";
  else if(isID(token))
    cout << "ID " << token << "\n";
  else if(isEqual(token))
    cout << "= " << token << "\n";
  else if(isPlus(token))
    cout << "+ " << token << "\n";
  else if(isMinus(token))
    cout << "- " << token << "\n";
  else if(isGreaterThan(token))
    cout << "> " << token << "\n";
  else if(isMult(token))
    cout << "* " << token << "\n";
  else if(isDivision(token))
    cout << "/ " << token << "\n";
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
  else if(isEqualEqual(token))
    cout << "== " << token << "\n";
  else if(isWhile(token))
    cout << "WHILE " << token << "\n";
  else if(isComment(token))
    cout << "comment " << token << "\n";
  else
    throw std::runtime_error(token);
}
//===========================================================================
void runLA(const std::string &nameOfFile){
  char ch;
  std::string buffer;
  std::fstream file(nameOfFile, std::fstream::in);

  if (!file.is_open()){
    cout << "Error opening file.\n";
    exit(0);
  }
//===========================================================================
  bool multichar = false, singlechar = false;
  while (file >> std::noskipws >> ch){
    if(singlechar || multichar){
      if(singlechar && ch == '\n')
        singlechar = false;

      if(multichar && ch == '*'){
        file >> ch;
        if(ch == EOF)
          break;

        if(ch == '/')
          multichar = false;
      }
      continue;
    }

    if(ch == '/'){
      std::string comm(1, ch);
      file >> ch;
      if(ch == EOF){
        printToken(comm);
        break;
      }

      if(ch == '*'){
        multichar = true;
        comm += ch;
      }
      else if(ch == '/'){
        singlechar = true;
        comm += ch;
      }
      if(multichar || singlechar){
        printToken(comm);
        continue;
      }
    }

    if(isNotLegal(std::string(1, ch))){
      if(!buffer.empty())
      {
        printToken(buffer);
        buffer = "";
      }
      continue;
    }

    if(isOperator(std::string(1, ch)))
    {
      if(!buffer.empty() && !isOperator(buffer))
      {
        printToken(buffer);
        buffer = "";
      }
    }

    if(isSemicolon(std::string(1, ch)))
    {
      if(!buffer.empty())
      {
        printToken(buffer);
        buffer = "";
      }
      if(isSemicolon(std::string(1, ch)))
      {
        printToken(std::string(1, ch));
        continue;
      }
    }
    buffer += ch;
  }
  file.close();
}
