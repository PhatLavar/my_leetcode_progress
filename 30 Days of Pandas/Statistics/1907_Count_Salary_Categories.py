import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    return pd.DataFrame({
        "category": ["Low Salary", "Average Salary", "High Salary"],
        "accounts_count": [
            accounts[accounts["income"] < 2e4].shape[0],
            accounts[(accounts["income"] >= 2e4) & (accounts["income"] <= 5e4)].shape[0],
            accounts[accounts["income"] > 5e4].shape[0]
        ]
    })