signtool sign /fd SHA256 /f "\GlobalSignCertificate\xxxxxxxxxxxxxxxxxxxxxxx.pfx" /p xxxxxxxx /ac "\GlobalSignCertificate\MSCrossCert.crt" /t http://timestamp.globalsign.com/scripts/timstamp.dll IoDrvSimple.sys

pause
