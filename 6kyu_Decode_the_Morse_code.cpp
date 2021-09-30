//https://www.codewars.com/kata/54b724efac3d5402db00065e

std::string decodeMorse(std::string morseCode) {
    // ToDo: Accept dots, dashes and spaces, return human-readable message
    std::string decoded;
    std::string sub;
  
  int last = 0;
  for (size_t i = 0; i < morseCode.size(); ++i)
  {
    if (morseCode[i] != ' ')
    {
      if (i - last > 2)
        decoded += " ";

      sub += morseCode[i];
      last = i;
    }
    else
    {
      decoded += MORSE_CODE[sub];
      sub.clear();
    }
  }
  
  decoded += sub == " " ? " " : MORSE_CODE[sub];
  
  return decoded[0] == ' ' ? decoded.substr(1, decoded.size() - 1) : decoded;
}
