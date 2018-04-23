#ifndef __COMPLEX__
#define __COMPLEX__
class complex
{
  public:
    complex(double re = 0, double im = 0) : r(re), i(im)
    {}

    double real() const
    {
        return r;
    }

    double imag() const
    {
        return i;
    }
    inline complex &operator+=(const complex &r);
    friend complex &__dapl(complex *ths, const complex &r);

  private:
    double r;
    double i;
};

complex &__dapl(complex *ths, const complex &r)
{
    ths->r += r.r;
    ths->i += r.i;
    return *ths;
}

complex &complex ::operator+=(const complex &r)
{
    return __dapl(this, r);
}
#endif