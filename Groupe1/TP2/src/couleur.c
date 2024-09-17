struct Color
{
    int r;
    int g;
    int b;
    int a;
};

struct ColorDistinct
{
    struct Color color;
    int count;
};

#include <stdio.h>

int main()
{
    struct Color colors[100];

    for (int i = 0; i < 100; i++)
    {
        colors[i].r = i % 10;
        colors[i].g = i % 10;
        colors[i].b = i % 10;
        colors[i].a = i % 10;
    }

    struct ColorDistinct distinct_colors[100];

    int distinct_colors_count = 0;

    for (int i = 0; i < 100; i++)
    {
        int color_index = -1;

        for (int j = 0; j < distinct_colors_count; j++)
        {
            if (colors[i].r == distinct_colors[j].color.r &&
                colors[i].g == distinct_colors[j].color.g &&
                colors[i].b == distinct_colors[j].color.b &&
                colors[i].a == distinct_colors[j].color.a)
            {
                color_index = j;
                break;
            }
        }

        if (color_index != -1)
        {
            distinct_colors[color_index].count++;
        }
        else
        {
            distinct_colors[distinct_colors_count].color = colors[i];
            distinct_colors[distinct_colors_count].count = 1;
            distinct_colors_count++;
        }
    }

    for (int i = 0; i < distinct_colors_count; i++)
    {
        printf("Color (R: %d, G: %d, B: %d, A: %d) - Occurrences: %d\n",
               distinct_colors[i].color.r, distinct_colors[i].color.g,
               distinct_colors[i].color.b, distinct_colors[i].color.a,
               distinct_colors[i].count);
    }

    return 0;
}