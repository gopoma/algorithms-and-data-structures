class Color {
    static WHITE = 0;
    static GREY = 1;
    static BLACK = 2;

    static initializeColor(vertices) {
        const color = {};
        vertices.forEach(v => {
            color[v] = Color.WHITE;
        });
        return color;
    }
}

class Graph {
    constructor(isDirected = false) {
        this.isDirected = isDirected;
        this.vertices = [];
        this.adjList = new Map();
    }

    addVertex(v) {
        if(!this.vertices.includes(v)) {
            this.vertices.push(v);
            this.adjList.set(v, []);
            return true;
        }
        return false;
    }

    addEdge(from, to) {
        if(!this.adjList.get(from)) {
            this.addVertex(from);
        }
        if(!this.adjList.get(to)) {
            this.addVertex(to);
        }

        this.adjList.get(from).push(to);
        if(!this.isDirected) {
            this.adjList.get(to).push(from);
        }
    }

    getVertices() {
        return this.vertices;
    }
    getAdjList() {
        return this.adjList;
    }

    toString() {
        let s = "";
        this.vertices.forEach((v) => {
            s += `${v} -> `;
            const neighbors = this.adjList.get(v);
            neighbors.forEach((n) => {
                s += `${n} `;
            });
            s += "\n";
        });
        return s;
    }

    static breadthFirstSearch(graph, startVertex, callback) {
        const vertices = graph.getVertices();
        const adjList = graph.getAdjList();
        const color = Color.initializeColor(vertices);
        const queue = [];
        const visited = [];

        queue.push(startVertex);

        while(queue.length !== 0) {
            const u = queue.shift();
            const neighbors = adjList.get(u);
            color[u] = Color.GREY;

            neighbors.forEach((w) => {
                if(color[w] === Color.WHITE) {
                    color[w] = Color.GRAY;
                    queue.push(w);
                }
            });

            color[u] = Color.BLACK;
            visited.push(u);
            if(callback) {
                callback(u);
            }
        }
        return visited;
    }
}

module.exports = Graph;