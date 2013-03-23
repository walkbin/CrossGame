set dst = "%1"

rd %dst /s
md %dst
xcopy  /E /I /L  ".\HelloCpp" "%dst"