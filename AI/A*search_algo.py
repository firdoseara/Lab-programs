import heapq
class Node:
    def __init__(self,state,parent=None,g=0,h=0):
        self.state = state
        self.parent = parent
        self.g = g
        self.h = h
    def f(self):
        return self.g + self.h
    def __lt__(self,other):
        return self.f() < other.f()
def astar_search(start_state,goal_state,heuristic):
    open_set = []
    closed_set = set()
    start_node = Node(start_state,g=0,h=heuristic(start_state,goal_state))
    heapq.heappush(open_set,start_node)
    while open_set:
        current_node = heapq.heappop(open_set)
        if current_node.state == goal_state:
            path = []
            while current_node:
                path.append(current_node.state)
                current_node = current_node.parent
            return path[::-1]
        closed_set.add(current_node.state)
        for neighbor_state in get_neighbors(current_node.state):
            if neighbor_state in closed_set:
                continue
            g = current_node.g + 1
            h = heuristic(neighbor_state,goal_state)
            neighbor_node = Node(neighbor_state,parent=current_node,g=g,h=h)
            if neighbor_node not in open_set:
                heapq.heappush(open_set,neighbor_node)
            elif g < neighbor_node.g:
                neighbor_node.g = g
                neighbor_node.parent = current_node
    return None 
def manhattan_distance(state,goal_state):
    return abs(state[0] - goal_state[0])+abs(state[1] - goal_state[1])
def get_neighbors(state):
    x,y = state
    neighbors = []
    for dx,dy in [(1,0),(-1,0),(0,1),(0,-1)]:
        nx,ny = x+dx , y+dy
        if 0 <= nx < GRID_WIDTH and 0 <= ny < GRID_HEIGHT:
            neighbors.append((nx,ny))
    return neighbors
GRID_WIDTH,GRID_HEIGHT = 5,5
start_state = (0,0)
goal_state = (4,4)
path = astar_search(start_state,goal_state,manhattan_distance)
print("Path found:",path)
