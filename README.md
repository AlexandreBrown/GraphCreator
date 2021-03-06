# Graph Creator  
A basic graph creation tool that can generate a weighted graph with a configurable number of vertices and edges (and random weights).  
## Supported output formats
- **DOT** : https://en.wikipedia.org/wiki/DOT_(graph_description_language)  
- **TP2**  
  
# Documentation  
## How to use Graph Creator  
- Build the project to generate an executable "GraphCreator"  
- Type the following command in the terminal, make sure you are in the GraphCreator executable directory.  
- The syntaxt goes as follow : 
  - `GraphCreator <desiredNumberOfVertices> <desiredNumberOfEdges> <outputFormat>`     
    - desiredNumberOfVertices : unsigned Int  
    - desiredNumberOfEdges : unsigned Int  
    - outputFormat : character
      - d : DOT output format
      - t : TP2 output format
### Examples  
- `GraphCreator 20 40 d`  
  - Creates a txt file with 20 vertices and 40 edges in the **DOT** output format
- `GraphCreator 20 40 t`  
  - Creates a txt file with 20 vertices and 40 edges in the **TP2** output format  

 ## How to use Dot (third party tool)    
 - Install Graphviz from here : https://graphviz.org/download/  
 - Generate a graph using GraphCreator (eg: `GraphCreator 20 40 d`)  
   - Let's assume it generated a file with the name "graph_2021-03-17_23:20:09.txt". 
 - Use Dot to generate an image from the graph (eg: `dot -Tpng -O graph_2021-03-17_23:20:09.txt`)  
   - You can then preview the graph using your image viewer of choice.  
   ![graph_2021-03-17_23:20:09 txt](https://user-images.githubusercontent.com/26939775/111569497-2bc42700-8779-11eb-81c5-5d7a998e50c6.png)
