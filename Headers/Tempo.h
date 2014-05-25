enum unit{
	H, M, S, MS
};
class Tempo
{
	int h;
	int m;
	int s;
	int ms;
public:
	//ms, s, m ou h;
	void addUTempo(unit u);
	Tempo();
	virtual ~Tempo();
};



