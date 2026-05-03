import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    management = employee.groupby(
        "managerId", 
        as_index=False)["id"].count().rename(columns={"id": "count"})
    managers = management[management["count"] >= 5]

    result = managers.merge(
        employee,
        left_on="managerId",
        right_on="id",
    )

    return result[["name"]]