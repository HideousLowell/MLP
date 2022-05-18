![](image/research.png)

# Research

The experiment was carried out on a test or training dataset emnist-letters.

### *Table 1 - Neural network parameters*

|  Hiden layes | ALPHA | Neuron's in hiden layers  | Epoch |
|  :-----: | :-----: | :-----: | :-----: | 
|  4 | 0.25 | 140 | 4 |

### *Table 2 - Result of the experiment*

|  | 10 runs | 100 runs| 1000 runs | Average time of 1 run |
| ------------- | :-----: | :-----: | :-----: | :-----: | 
| `Matrix perceptron` | 157 sec. | 1573 sec. | 15736 sec. | 15.722 sec. |
| `Graph perceptron` | 198 sec. | 1946 sec. | 19275 sec. | 19.512 sec. |

### Conclusion
1. If we evaluate the algorithm `forward propagation` then the speed of the matrix and graph implementation `O(n^2)`.
2. If we evaluate the algorithm `back propagation` then the speed of the matrix and graph implementation `O(n^3)`.
3. The graph implementation uses the `double vector` data type, while the matrix implementation uses a `double pointer`, which is more optimized.
4. Also the graph implementation initializes `784 Neuron` objects and `140 Layer` objects, but the matrix implementation uses 1 `S21Matrix (784, 140)` object which is faster.

