#ifndef WINDOW_H
#define WINDOW_H

class Window
{
  int m_width, m_height;

  public:
    Window(int width, int height, bool fullscreen = false);

    int GetWidth() { return m_width; }
    int GetHeight() { return m_height; }

    void Swap();
};

#endif
