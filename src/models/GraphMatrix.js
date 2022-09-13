const { generateSquareMatrix } = require("../helpers/generateMatrix");

class GraphMatrix {
    static ON = 1;
    static OFF = 0;

    constructor(numNodes = 0) {
        this.numNodes = numNodes;
        this.adjacency = generateSquareMatrix(this.numNodes, GraphMatrix.OFF);
    }

    isValidNode(node) {
        return node >= 0 && node < this.numNodes;
    }

    // Taking into consideration an undirected graph
    addEdge(from, to) {
        if(this.isValidNode(from) && this.isValidNode(to)) {
            this.adjacency[from][to] = GraphMatrix.ON;
            this.adjacency[to][from] = GraphMatrix.ON;
            return true;
        }
        return false;
    }

    // Taking into consideration an undirected graph
    removeEdge(from, to) {
        if(this.isValidNode(from) && this.isValidNode(to)) {
            this.adjacency[from][to] = GraphMatrix.OFF;
            this.adjacency[to][from] = GraphMatrix.OFF;
            return true;
        }
        return false;
    }

    depthFirstSearch(n) {
        if(this.numNodes === 0) {
            return {
                success: false,
                message: "Graph is Empty!"
            };
        } else if(!this.isValidNode(n)) {
            return {
                success: false,
                message: "Invalid Node!"
            };
        }
        return this.#depthFirstSearchR(n, []);
    }
    #depthFirstSearchR(n, visited) {
        visited.push(n);
        for(let i = 0; i < this.numNodes; i++) {
            if(this.adjacency[n][i] === GraphMatrix.ON && !visited.includes(i)) {
                this.#depthFirstSearchR(i, visited);
            }
        }
        return visited;
    }

    countConnectedComponents() {
        const nodes = new Set();
        for(let i = 0; i < this.numNodes; i++) {
            nodes.add(i);
        }

        let cc = 0;
        while(nodes.size !== 0) {
            const dfs = this.depthFirstSearch(nodes.size - 1);
            for(let node of dfs) {
                nodes.delete(node);
            }
            cc++;
        }
        return cc;
    }
}

module.exports = GraphMatrix;