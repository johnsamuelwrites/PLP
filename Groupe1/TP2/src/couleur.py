class Color:
    def __init__(self, r, g, b, a):
        self.r = r
        self.g = g
        self.b = b
        self.a = a

colors = []
for i in range(100):
    color = Color(i % 10, i % 10, i % 10, i % 10)
    colors.append(color)

distinct_colors = {}
for color in colors:
    color_tuple = (color.r, color.g, color.b, color.a)
    if color_tuple in distinct_colors:
        distinct_colors[color_tuple] += 1
    else:
        distinct_colors[color_tuple] = 1

for color, count in distinct_colors.items():
    print(f"Color (R: {color[0]}, G: {color[1]}, B: {color[2]}, A: {color[3]}) - Occurrences: {count}")