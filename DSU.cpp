//int parent[n+1]
//int size[n+1]
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
// Приведём реализацию ранговой эвристики на основе размеров деревьев:

void make_set (int v) {
	parent[v] = v;
	size[v] = 1;
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (size[a] < size[b])
			swap (a, b);
		parent[b] = a;
		size[a] += size[b];
	}
}
// Приведём реализацию ранговой эвристики на основе глубины деревьев:

void make_set (int v) {
	parent[v] = v;
	rank[v] = 0;
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rank[a] < rank[b])
			swap (a, b);
		parent[b] = a;
		if (rank[a] == rank[b])
			++rank[a];
	}
}
// Приведём здесь итоговую реализацию системы непересекающихся множеств, реализующую обе указанные эвристики (используется ранговая эвристика относительно глубин деревьев):

void make_set (int v) {
	parent[v] = v;
	rank[v] = 0;
}
 
int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}
 
void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (rank[a] < rank[b])
			swap (a, b);
		parent[b] = a;
		if (rank[a] == rank[b])
			++rank[a];
	}
}