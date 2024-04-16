#include <iostream>
#include "brightener.h"

int main()
{

    const auto image = std::make_shared<Image>(512, 512);

    if (image->IsValid())
    {
        std::cout << "Brightening a 512 x 512 image\n";
        const ImageBrightener brightener(image);

        const int attenuatedCount = brightener.BrightenWholeImage();
        std::cout << "Attenuated " << attenuatedCount << " pixels\n";
        std::cout << "... in an image of: " << image->getRows() << " x " << image->getColumns() << "\n";
        return 0;
    }
    else 
    {
        std::cout << "Not a valid image... did nothing\n";
        return 1;
    }
}
