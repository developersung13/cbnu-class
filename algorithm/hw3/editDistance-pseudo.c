EDITDISTANCE(A[1..m], B[1, ..n]):
  for j⟵0 to n
    Edit[0, j]⟵j
  for i⟵1 to m
    Edit[i, 0]⟵i
    for j⟵1 to n
      ins⟵Edit[i, j-1]+1
      del⟵Edit[i-1, j]+1
      if A[i] = B[j]
        rep⟵Edit[i-1, j-1]
      else
        rep⟵Edit[i-1, j-1] + 1
      Edit[i, j]⟵min{ins, del, rep}
  return Edit[m, n]
