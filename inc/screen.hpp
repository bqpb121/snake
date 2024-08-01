#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

class Screen
{
public:
    static Screen *instance()
    {
        static Screen instance("/dev/fb0", 800, 480);
        return &instance;
    }
    int getW(void);
    int getH(void);
    int getfd(void);
    int *getplcd(void);
    void draw(int x, int y, unsigned int color);
    ~Screen();

private:
    Screen(const char *devpath, int w, int h);
    Screen(const Screen &) = delete;
    Screen &operator=(const Screen &) = delete;
    const char *_devname;
    int _w;
    int _h;
    int _fd;
    int *_plcd;
};
#endif