#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//less_equal<int> and upper_bound(not find) for multi_orderedset

// find_by_order(p)	//Retorna um ponteiro para o p-ésimo elemento do set. Se p é maior que o tamanho de n, retorna o fim do set. Index em 0
// order_of_key(v)	//Retorna quantos elementos são menores que v.

// Mesmo set com operações de find_by_order e order_of_key
