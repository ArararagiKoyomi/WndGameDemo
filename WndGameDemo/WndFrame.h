#ifndef WGD_WINDOW_FRAME_H
#define WGD_WINDOW_FRAME_H

namespace DEMO
{
	class WndFrame
	{
	public:
		struct windowAttr
		{
			int width;
			int height;
		};
		WndFrame(int width, int height);
		~WndFrame();
		bool upgradeSize(int width, int height);
		bool upgradeWidth(int width);
		bool upgradeHeight(int height);
		int getWidth();
		int getHeight();



	private:
		windowAttr m_windowAttr;
	};



}

#endif