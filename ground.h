#ifndef GROUND_H
#define GROUND_H

#include <iostream>
#include <backgrounditem.h>
#include <defines.hpp>


class Ground : public BackgroundItem
{
    public:

      Ground(b2World& World, int x, int y,  texture_param_t param);
      virtual ~Ground();

      void startContact();
      void endContact();

    protected:




    private:
        Ground();

};

#endif // GROUND_H
