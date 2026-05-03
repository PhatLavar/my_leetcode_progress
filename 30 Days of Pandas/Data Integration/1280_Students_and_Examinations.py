import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    student_subject = students.merge(
        subjects,
        how="cross"
    )
    
    exam_count = examinations.groupby(
        ["student_id", "subject_name"],
        as_index=False
    ).size().rename(columns={
        "size": "attended_exams"
    })

    result = student_subject.merge(
        exam_count,
        on=["student_id", "subject_name"],
        how="left"
    )

    result["attended_exams"] = result["attended_exams"].fillna(0).astype(int)

    return result.sort_values(
        by=["student_id", "subject_name"],
        ascending=True
    )[["student_id", "student_name", "subject_name", "attended_exams"]]