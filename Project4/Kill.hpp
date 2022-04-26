namespace MuSeoun_Engine {
	class Kill
	{
	public:
		int x;
		int y;
		bool killed;

		Kill()
		{
			x = 45;
			y = 10;
			killed = false;

		}
		~Kill()
		{

		}
		void killmove()
		{
			x --;
		}
	};
}
