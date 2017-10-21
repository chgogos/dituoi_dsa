int main() {
  int d[3][3][2];
  int e[3][3][2][2];
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 2; k++) {
        d[i][j][k] = 1;
        for (int l = 0; l < 2; l++)
          e[i][j][k][l] = 1;
      }
}