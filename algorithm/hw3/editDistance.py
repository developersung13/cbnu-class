def edit_distance(str1, str2):
    len_str1 = len(str1)
    len_str2 = len(str2)

    # 행렬 초기화
    dp = [[0 for x in range(len_str2+1)] for x in range(len_str1+1)]

    # 행렬의 첫 번째 행과 열을 채움
    for i in range(len_str1+1):
        for j in range(len_str2+1):
            if i == 0:
                dp[i][j] = j  # 첫 번째 행: j에 대한 삽입
            elif j == 0:
                dp[i][j] = i  # 첫 번째 열: i에 대한 삭제
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j],   # 삭제
                                   dp[i][j-1],   # 삽입
                                   dp[i-1][j-1]) # 대체

    # 행렬 출력
    for row in dp:
        print(row)

    return dp[len_str1][len_str2]

# 두 문자열
str1 = "He cannot be reliable"
str2 = "He can be unreliable"

# 편집 거리 계산 및 출력
distance = edit_distance(str1, str2)
print("Edit Distance:", distance)
