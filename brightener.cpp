#include "brightener.h"

ImageBrightener::ImageBrightener(const std::shared_ptr<Image>& inputImage)
                : m_inputImage(inputImage)
{
}

int ImageBrightener::BrightenWholeImage() const
{
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedPixelCount = 0;

    const auto imageRows = m_inputImage->getRows();
    const auto imageColumns = m_inputImage->getColumns();
    const auto imagePixels = m_inputImage->getPixels();

    for (int x = 0; x < imageRows; x++) {
        for (int y = 0; y < imageColumns; y++) {
            if (imagePixels[x * imageColumns + y] > (255 - 25)) {
                ++attenuatedPixelCount;
                imagePixels[x * imageColumns + y] = 255;
            }
            else {
                const int pixelIndex = x * imageColumns + y;
                imagePixels[pixelIndex] += 25;
            }
        }
    }
    return attenuatedPixelCount;
}
