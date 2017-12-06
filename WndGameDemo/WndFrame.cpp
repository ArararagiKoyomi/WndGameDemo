#include "WndFrame.h"

DEMO::WndFrame::WndFrame(int width, int height)
{
	m_windowAttr.width = width;
	m_windowAttr.height = height;
	return;
}

DEMO::WndFrame::~WndFrame()
{

}

bool DEMO::WndFrame::upgradeSize(int width, int height)
{
	m_windowAttr.width = width;
	m_windowAttr.height = height;
	return true;
}

bool DEMO::WndFrame::upgradeWidth(int width)
{
	m_windowAttr.width = width;
	return true;
}

bool DEMO::WndFrame::upgradeHeight(int height)
{
	m_windowAttr.height = height;
	return true;
}

int DEMO::WndFrame::getWidth()
{
	return m_windowAttr.width;
}

int DEMO::WndFrame::getHeight()
{
	return m_windowAttr.height;
}
