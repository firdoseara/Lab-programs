class State:
    def __init__(self,missionaries,cannibals,boat):
        self.missionaries=missionaries
        self.cannibals=cannibals
        self.boat=boat
    def is_valid(self):
        if self.missionaries < 0 or self.missionaries > 3:
            return False
        if self.cannibals < 0 or self.cannibals > 3:
            return False
        if self.missionaries < self.cannibals and self.missionaries > 0:
            return False
        if 3 - self.missionaries < 3 - self.cannibals and 3 - self.missionaries > 0:
            return False
        return True
    def is_goal(self):
        return self.missionaries == 0 and self.cannibals == 0 and self.boat == 0
    def __eq__(self,other):
        return self.missionaries == other.missionaries and self.cannibals == other.cannibals  and self.boat == other.boat
    def __hash__(self):
        return hash((self.missionaries, self.cannibals, self.boat))
    def __str__(self):
        return f"M:{self.missionaries}, C:{self.cannibals}, B:{'left' if self.boat == o else 'right'}"
def successors(state):
    children=[]
    if state.boat == 0:
        for m in range(3):
            for c in range(3):
                if 1 <= m+c <=2:
                    new_state = State(state.missionaries - m, state.cannibals -c, 1)
                    if new_state.is_valid():
                        children.append(new_state)
    else:
        for m in range(3):
            for c in range(3):
                if 1<= m+c <=2:
                    new_state = State(state.missionaries + m, state.cannibals + c,0)
                    if new_state.is_valid():
                        children.append(new_state)
    return children
def best_first_search():
    initial_state=State(3,3,0)
    frontier = [initial_state]
    explored = set()
    while frontier:
        frontier.sort(key = lambda state:(state.missionaries + state.cannibals)* 10+ state.boat)
        state = frontier.pop(0)
        if state.is_goal():
            return state
        explored.add(state)
        for child in successors(state):
            if child not in explored and child not in frontier:
                frontier.append(child)
    return None
def print_solution(solution):
    if solution:
        path=[]
        while solution:
            path.append(solution)
            solution=solution.parent
        path.reverse()
        for i, state in enumerate(path):
            print(f"Step{i}: {state}")
    else:
        print("No solution found.")
if __name__ == "__main__":
    solution = best_first_search()
    print_solution(solution)
