void StartBoard(char* map);

void Move(char* map, char letter, bool First);

void Board (char* map);

bool Mode();

bool IsWin(char* map, char letter);

bool Side();

bool Draw (char* map);

//short score_attak(char* field, char Us_letter, char Com_letter, short y, short x);

//short score_defence(char* field, char Com_letter, char Us_letter, short y, short x);

void Bot(char* map, char com_letter, char us_letter);

bool Again();