import math
from m3c import Position

def mag(pos):
    return math.sqrt(pos.x * pos.x + pos.y * pos.y + pos.z * pos.z)

fn = mag


