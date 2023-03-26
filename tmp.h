#ifndef TMP_H
#define TMP_H


class tmp
{
public:
    tmp();
    tmp(int a);
    tmp(int x, int y);
    tmp(int a, int b, int c, int d);

    union{
        struct{
            int a, b, c, d;
        };

        struct{
            int j, k, l;
        };

        struct{
            int x, y;
        };

        struct{
            int p;
        };
    };

};

#endif // TMP_H
