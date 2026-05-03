import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    employee["max_salary"] = employee.groupby("departmentId")["salary"].transform("max")
    highest = employee[
        employee["max_salary"] == employee["salary"]
    ]

    highest = highest.merge(
        department,
        left_on="departmentId",
        right_on="id"
    )

    return highest[["name_y", "name_x", "max_salary"]].rename(columns={
        "name_y": "Department",
        "name_x": "Employee",
        "max_salary": "Salary"
    })