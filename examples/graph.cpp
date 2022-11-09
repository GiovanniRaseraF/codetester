#include "graph.hpp"

densegraph::densegraph(int n){
    for(int i = 0; i < n; i++){
        admatrix.push_back(std::vector<int>(n, 0));
    }
}

std::set<int> densegraph::getAllNeigh(int v) const {
    std::set<int> ret{};

    int n = admatrix.at(0).size();
    // Controllo riga e colonna
    for(int w = 0; w < n; w++){
        if(admatrix[v-1][w]){
            ret.insert(w+1); 
        }
        if(admatrix[w][v-1]){
            ret.insert(w+1);
        }
    }

    return ret;
}

std::set<int> densegraph::getOutNeigh(int v) const {
    std::set<int> ret{};

    int n = admatrix.at(0).size();
    // Controllo riga
    for(int w = 0; w < n; w++){
        if(admatrix[v-1][w]){
            ret.insert(w+1); 
        }
    }

    return ret;
} 

std::set<int> densegraph::getInNeigh(int v) const {
    std::set<int> ret{};

    int n = admatrix.at(0).size();
    // Controllo colonna
    for(int w = 0; w < n; w++){
        if(admatrix[w][v-1]){
            ret.insert(w+1);
        }
    }

    return ret;
}

void densegraph::addSide(int from, int to){
    admatrix[from-1][to-1] = 1;
}

bool densegraph::isSide(int from, int to) const {
    return admatrix[from-1][to-1]; 
}

bool densegraph::isConnected() const {
    int k = 0;
    int n = admatrix.at(0).size();
    std::vector<int> L(n, 0); 
    std::queue<int> S{};

    for(int i = 0; i < n; i++){
        if(L[i] == 0){
            k++;
            L[i] = k;
            S.push(i);
            while(!S.empty()){
                int v = S.front();
                S.pop();
                for(const int w : getAllNeigh(v+1)){
                    if(L[w-1] == 0){
                        L[w-1] = k;
                        S.push(v);
                    }
                }
            }
        }
    }

    return k <= 1;
}

std::ostream &operator<<(std::ostream &os, const densegraph &d){
    int n = d.admatrix.at(0).size();
    
    os << std::setw(3) << "->" << ":";
    for(int i = 0; i < n; i++) os << std::setw(3) << i+1;
    os << std::endl;
    for(int i = 0; i < n; i++){
        os << std::setw(3) << i+1 << ":";
        for(auto v : d.admatrix[i]){
            os << std::setw(3) << v;
        }
        os << std::endl;
    }

    return os;
}