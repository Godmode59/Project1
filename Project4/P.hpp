namespace MuSeoun_Engine {
	class P
	{
	public:
		int x, y;
		P()
		{
			x = 20, y = 10;
		}
		~P()
		{

		}
		void getKeyDowned()
		{
			y = 7;
		}
		void getKeyUped()
		{
			y = 10;
		}
	};
}
