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
}

module.exports = Graph;