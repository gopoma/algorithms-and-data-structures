const Graph = require("../models/Graph");

const Chai = require("chai");
const { expect } = Chai;

// eslint-disable-next-line
describe("Graphs: Adjacency List Implementation", () => {
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