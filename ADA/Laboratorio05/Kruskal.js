const graph = [
    [0, 5, 0, 5, 0, 0],
    [5, 0, 3, 0, 5, 3],
    [0, 3, 0, 2, 2, 3],
    [5, 0, 2, 0, 2, 0],
    [0, 5, 2, 2, 0, 3],
    [0, 3, 3, 0, 3, 0]
];

/* const graph = [
    [0, 2, 2, 0, 0, 0],
    [2, 0, 2, 2, 2, 0],
    [2, 2, 0, 2, 0, 2],
    [0, 2, 2, 0, 2, 2],
    [0, 2, 0, 2, 0, 2],
    [0, 0, 2, 2, 2, 0]
]; */

/*
const graph = [
    [0, 2, 2, 2, 2, 0],
    [2, 0, 2, 0, 2, 0],
    [2, 2, 0, 2, 2, 0],
    [2, 0, 2, 0, 2, 2],
    [2, 2, 2, 2, 0, 2],
    [0, 0, 0, 2, 2, 0]
];
*/

/* const graph = [
    [0, 2, 2, 3],
    [2, 0, 2, 0],
    [2, 2, 0, 3],
    [3, 0, 3, 0]
]; */

console.table(graph);

const initializeCost = graph => graph.map(component => component.map(value => value === 0 ? Number.MAX_SAFE_INTEGER : value));

const generateSquareMatrix = dimension => {
    const mtx = [];
    for(let i = 0; i < dimension; i++) {
        mtx.push([]);
        for(let j = 0; j < dimension; j++) {
            mtx[i].push(0);
        }
    }
    return mtx;
};

const find = (i, parent) => {
    while(parent[i]) {
        i = parent[i];
    }
    return i;
};

const union = (i, j, parent) => {
    if(i !== j) {
        parent[i] = j;
        return true;
    }
    return false;
};

// graph should be a conected undirected graph
const kruskal = graph => {
    const {length} = graph;
    const parent = [];
    let ne = 0;
    let a, b, u, v;
    const cost = initializeCost(graph);
    const result = generateSquareMatrix(length);

    while(ne < length - 1) {
        for(let i = 0, min = Number.MAX_SAFE_INTEGER; i < length; i++) {
            for(let j = 0; j < length; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        console.log("***************");
        console.log("u:", u, "v:", v);
        u = find(u, parent);
        v = find(v, parent);
        console.log("u:", u, "v:", v);
        console.log("***************");
        const ok = union(u, v, parent);
        if(ok) {
            result[a][b] = result[b][a] = cost[a][b];
            ne++;
        }
        cost[a][b] = cost[b][a] = Number.MAX_SAFE_INTEGER;
    }
    return result;
};

const getSum = mtx => mtx.reduce((result, current) => result + current.reduce((sum, x) => sum + x), 0);

console.table(kruskal(graph));
// console.log(getSum(kruskal(graph))/2);