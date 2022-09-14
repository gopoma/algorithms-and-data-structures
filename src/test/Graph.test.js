const Graph = require("../models/Graph");

const Chai = require("chai");
const { expect } = Chai;

// eslint-disable-next-line
describe("Graphs: Adjacency List Implementation (ALI)", () => {
    // eslint-disable-next-line
    it("Should build a Graph", () => {
        const graph = new Graph();
        const myVertices = ["A", "B", "C", "D", "E", "F", "G", "H", "I"];

        myVertices.forEach((v) => {
            graph.addVertex(v);
        });

        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("A", "D");
        graph.addEdge("C", "D");
        graph.addEdge("C", "G");
        graph.addEdge("D", "G");
        graph.addEdge("D", "H");
        graph.addEdge("B", "E");
        graph.addEdge("B", "F");
        graph.addEdge("E", "I");
        const result = graph.toString();

        expect(result).to.be.a("string");
        expect(result).to.be.equal(`A -> B C D 
B -> A E F 
C -> A D G 
D -> A C G H 
E -> B I 
F -> B 
G -> C D 
H -> D 
I -> E 
`);
    });
});

// eslint-disable-next-line
describe("ALI: Breadth First Search", () => {
    const graph = new Graph();
    const myVertices = ["A", "B", "C", "D", "E", "F", "G", "H", "I"];
    // eslint-disable-next-line
    beforeEach(() => {
        myVertices.forEach((v) => {
            graph.addVertex(v);
        });

        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("A", "D");
        graph.addEdge("C", "D");
        graph.addEdge("C", "G");
        graph.addEdge("D", "G");
        graph.addEdge("D", "H");
        graph.addEdge("B", "E");
        graph.addEdge("B", "F");
        graph.addEdge("E", "I");
    });
    // eslint-disable-next-line
    it("Case 1", () => {
        const result = Graph.breadthFirstSearch(graph, myVertices[0]);
        expect(result).to.be.an("array");
        expect(result).to.eql(["A", "B", "C", "D", "E", "F", "G", "H", "I"]);
    });
    // eslint-disable-next-line
    it("Case 2", () => {
        const result2 = Graph.breadthFirstSearch(graph, myVertices[1]);
        expect(result2).to.be.an("array");
        expect(result2).to.be.eql(["B", "A", "E", "F", "C", "D", "I", "G", "H"]);
    });
    // eslint-disable-next-line
    it("Case 3", () => {
        const result3 = Graph.breadthFirstSearch(graph, myVertices[2]);
        expect(result3).to.be.an("array");
        expect(result3).to.be.eql(["C", "A", "D", "G", "B", "H", "E", "F", "I"]);
    });
});