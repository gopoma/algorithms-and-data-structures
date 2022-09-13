function generateMatrix(rows, cols, init) {
    const mtx = [];
    for(let i = 0; i < rows; i++) {
        mtx.push([]);
        for(let j = 0; j < cols; j++) {
            mtx[i].push(init);
        }
    }
    return mtx;
}

function generateSquareMatrix(n, init) {
    return generateMatrix(n, n, init);
}

module.exports = {
    generateMatrix,
    generateSquareMatrix
};