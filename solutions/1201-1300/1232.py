class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        dx = coordinates[1][0] - coordinates[0][0]
        dy = coordinates[1][1] - coordinates[0][1]
        for x, y in coordinates[1:]:
            dx1 = x - coordinates[0][0]
            dy1 = y - coordinates[0][1]
            if dy * dx1 != dx * dy1:
                return False
        return True
