#pragma once
#include <cstdint>
#include <iostream>

constexpr uint16_t ImageRowsLimit = 1024;
constexpr uint16_t ImageColumnsLimit = 1024;

class Image
{
public:
    Image(const uint16_t rows, const uint16_t columns)
        : m_rows(rows)
        , m_columns(columns)
    {
        const auto imageSize = static_cast<size_t>(m_rows * m_columns);
        m_pixels = new uint8_t[imageSize];
        memset(m_pixels, NULL, imageSize);
    }

    ~Image()
    {
        std::cout << "freeing pixel memory.\n";
        delete[] m_pixels;
    }

    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;
    Image(const Image&&) = delete;
    Image& operator=(const Image&&) = delete;


    uint16_t getRows() const
    {
        return m_rows;
    }

    uint16_t getColumns() const
    {
        return m_columns;
    }

    uint8_t* getPixels() const
    {
        return m_pixels;
    }

    bool IsValid() const
    {
        if (m_columns <= ImageColumnsLimit && m_rows <= ImageRowsLimit) 
        {
            return true;
        }
        return false;
    }

private:
    const uint16_t m_rows;
    const uint16_t m_columns;
    uint8_t* m_pixels; // max 1k x 1k image
};
