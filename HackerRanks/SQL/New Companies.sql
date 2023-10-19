SELECT C.company_code, C.founder, 
       COUNT(DISTINCT L.lead_manager_code), 
       COUNT(DISTINCT S.senior_manager_code), 
       COUNT(DISTINCT M.manager_code), 
       COUNT(DISTINCT E.employee_code) 
FROM Company AS C LEFT JOIN Lead_Manager AS L ON C.company_code = L.company_code 
                  LEFT JOIN Senior_Manager AS S ON L.lead_manager_code = S.lead_manager_code
                  LEFT JOIN Manager AS M ON S.senior_manager_code = M.senior_manager_code
                  LEFT JOIN Employee AS E ON M.manager_code = E.manager_code
GROUP BY C.company_code, C.founder
ORDER BY C.company_code
