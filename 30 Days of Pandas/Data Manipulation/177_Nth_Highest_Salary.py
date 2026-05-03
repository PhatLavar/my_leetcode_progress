import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    salaries = employee["salary"].drop_duplicates().sort_values(ascending=False)

    if N <= 0 or N > len(salaries):
        return pd.DataFrame({f"getNthHighestSalary({N})": [None]})
    else:
        return pd.DataFrame({f"getNthHighestSalary({N})": [salaries.iloc[N - 1]]})