//https://www.codewars.com/kata/54acc128329e634e9a000362

#include <string>
#include <vector>

std::map<std::string, int> stateE = { 
  {"CLOSED",0},  {"LISTEN", 1}, {"SYN_SENT", 2},  {"SYN_RCVD", 3}, 
  {"ESTABLISHED", 4},  {"CLOSE_WAIT", 5 }, { "LAST_ACK", 6},  
  {"FIN_WAIT_1", 7}, { "FIN_WAIT_2", 8},  {"CLOSING", 9}, 
  { "TIME_WAIT", 10}, {"END", 11} 
};

std::map<std::string, int> eventE = { 
  {"APP_PASSIVE_OPEN", 0}, {"APP_ACTIVE_OPEN", 1}, {"APP_SEND", 2}, 
  {"APP_CLOSE", 3}, {"APP_TIMEOUT", 4}, {"RCV_SYN", 5}, 
  {"RCV_ACK", 6}, {"RCV_SYN_ACK", 7}, {"RCV_FIN", 8}, 
  {"RCV_FIN_ACK", 9}, {"END", 10} 
};

std::string traverse_TCP_states(const std::vector<std::string>& events) {

  std::vector<std::vector<int>> map(stateE["END"]);
  std::for_each(map.begin(), map.end(), [&](std::vector<int>& inner) {inner.resize(eventE["END"], -1); });

  map[0][0] = 1;
  map[0][1] = 2;
  map[1][2] = 2;
  map[1][3] = 0;
  map[1][5] = 3;
  map[2][3] = 0;
  map[2][5] = 3;
  map[2][7] = 4;
  map[3][3] = 7;
  map[3][6] = 4;
  map[4][3] = 7;
  map[4][8] = 5;
  map[5][3] = 6;
  map[6][6] = 0;
  map[7][6] = 8;
  map[7][8] = 9;
  map[7][9] = 10;
  map[8][8] = 10;
  map[9][6] = 10;
  map[10][4] = 0;

  int state = 0;
  for (int i = 0; i < events.size(); ++i)
  {
    int eventIdx = eventE[events[i]];
    state = map[state][eventIdx];

    if (state == -1)
      return "ERROR";
  }

  for (auto it = stateE.begin(); it != stateE.end(); ++it)
  {
    if (it->second == state)
      return it->first;
  }

  return "ERROR";
}
