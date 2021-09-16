using Microsoft.VisualStudio.TestTools.UnitTesting;
using ClassLibraryПароли123;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ClassLibraryПароли123.Tests
{
    [TestClass()]
    public class PasswordCheckerTests
    {
        [TestMethod()]
        public void Check_Symbols_ReturnsTrue()
        {
            // Arrange
            string password = "Danya18060$3";
            bool expected = true;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.AreEqual(expected, actual);
        }
        [TestMethod()]
        public void Check_Symbols_ReturnsFalse()
        {
            // Arrange
            string password = "1111";
            bool expected = false;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.IsFalse(actual);
        }
        [TestMethod()]
        public void Check_22Symbols_ReturnsFalse()
        {
            // Arrange
            string password = "11118348573248957845345";
            bool expected = false;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.IsFalse(actual);
        }
        [TestMethod()]
        public void Check_IsDigit_ReturnsTrue()
        {
            // Arrange
            string password = "64736223bvD)";
            bool expected = true;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.AreEqual(expected, actual);
        }
        [TestMethod()]
        public void Check_NotDigit_ReturnsFalse()
        {
            // Arrange
            string password = "hds";
            bool expected = false;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.IsFalse(actual);
        }
        [TestMethod()]
        public void Check_SpecialSymbols_ReturnsTrue()
        {
            // Arrange
            string password = "PEIWODOa$2S";
            bool expected = true;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.AreEqual(expected, actual);
        }
        [TestMethod()]
        public void Check_NotSpecialSymbols_ReturnsFalse()
        {
            // Arrange
            string password = "DANEK";
            bool expected = false;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.IsFalse(actual);
        }
        [TestMethod()]
        public void Check_Uppercase_ReturnsTrue()
        {
            // Arrange
            string password = "dAneche18(k";
            bool expected = true;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.AreEqual(expected, actual);
        }
        [TestMethod()]
        public void Check_4Uppercase_ReturnsFalse()
        {
            // Arrange
            string password = "kakdela";
            bool expected = false;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.IsFalse(actual);
        }
        [TestMethod()]
        public void Check_8Lowercase_ReturnsTrue()
        {
            // Arrange
            string password = "cAd1diLLAc&$";
            bool expected = true;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.AreEqual(expected, actual);
        }
        [TestMethod()]
        public void Check_4Lowercase_ReturnsFalse()
        {
            // Arrange
            string password = "DANEK123";
            bool expected = false;
            // Act
            bool actual = PasswordChecker.validatePassword(password);
            // Assert
            Assert.IsFalse(actual);
        }
    }
}
