# Parity-Bit-Com
This project consists of 3 source files:
<ol>
  <li>Encoder</li>
  <p>This is part separates every character into two nibbles and adds parity bits.</p>
  <li>Channel</li>
  <p>This part simulates added noise to the encoded data by flipping a random bit.</p>
  <li>Decoder</li>
  <p>This part receives the data and corrects the corrupted data with the help of the parity bits.</p>
</ol>
The data communication is between 4 files:
<ul>
  <li>inputData
    <li>encodedData
      <li>transmittedData
        <li>decodedData
          </ul>
In the end the inputData file should be equal to the decodedData file and both transmittedData and encodedData should be unreadable
