#include "stdafx.h"
#include "Core.h"
#include "Framework.h"

int main()
{
    Framework framework;
    
    framework.Init();
    framework.Update();

    //while (renderWindow->isOpen())
    //{

    //    // 랜더 매니저에게 전달
    //    renderWindow->clear();
    //    renderWindow->display();
    //}

    return 0;
}