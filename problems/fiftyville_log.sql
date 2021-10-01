-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT transcript FROM interviews WHERE day = 28 AND transcript LIKE "%courthouse%";

--Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
--I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket

SELECT name, phone_number
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = "withdraw" AND license_plate in
(SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND 5 < minute < 25 AND activity = "exit")
AND phone_number in (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60)
INTERSECT
SELECT name, phone_number
FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND year = 2020 AND month = 7 AND day = 29 AND flight_id =
(SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29 ORDER BY hour LIMIT 1);

--Ernest | (367) 555-5533 | 5773159633 thief
--Madison | (286) 555-6063 | 1988161715


SELECT name, phone_number, passport_number
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE caller in
(SELECT phone_number FROM people WHERE passport_number = 5773159633 OR passport_number = 1988161715)
AND year = 2020 AND month = 7 AND day = 28 AND duration < 60;

--id | name | phone_number | passport_number | license_plate
--250277 | James | (676) 555-6554 | 2438825627 | Q13SVG6
--864400 | Berthold | (375) 555-8161 |  | 4V16VO0  The ACCOMPLICE

SELECT * FROM bank_accounts WHERE person_id = 250277; -- у Джеймса нет банковского счета
SELECT * FROM bank_accounts WHERE person_id = 864400;

--account_number | person_id | creation_year
--94751264 | 864400 | 2019

SELECT city FROM airports
JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.id = (SELECT flight_id FROM passengers WHERE passport_number = 5773159633);

--London